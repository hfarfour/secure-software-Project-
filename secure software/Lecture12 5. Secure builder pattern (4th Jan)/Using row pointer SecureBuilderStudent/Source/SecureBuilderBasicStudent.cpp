#include <iostream>
#include <list>
#include <string>
#include <map>
#include <vector>
#include <direct.h>
using namespace std;

enum class TrustLevel
{ complete, little, bogus };

class Trust 
{
	map<string, TrustLevel> TrustMap;
public:
	Trust(void) {
		TrustMap["14.8.9.28"] = TrustLevel::complete;
		TrustMap["14.8.9.29"] = TrustLevel::little;
		TrustMap["14.8.9.30"] = TrustLevel::bogus;
	}
	TrustLevel getTrustLevel(string ip) {
		map<string, TrustLevel>::iterator it;
		it = TrustMap.find(ip);
		if (it != TrustMap.end())
			return it->second;
		else return TrustLevel::bogus;
	}
};

class Subject
{
	string ipAddr{ "0.0.0.0" };
	TrustLevel trustLevel{ TrustLevel::bogus };
public:
	Subject(string newIpAddr)
	{
		ipAddr = newIpAddr;
		Trust t;
		trustLevel = t.getTrustLevel(ipAddr);
	}

	~Subject(void) 
	{
		ipAddr = "0.0.0.0";
		trustLevel = TrustLevel::bogus;
	}
	TrustLevel getTrustLevel(void) const
	{
		return trustLevel;
	}
	string getIpAddr(void) const
	{
		return ipAddr; 
	}
};


class Action {
	string action{ "" };
public:
	void setAction(const string aaction) { action = aaction; }
	string getAction(void) const { return action; }
};

class Source 
{
	string source{ "" };
public:
	void setSource(const string asource) { source = asource; }
	string getSource(void) const { return source; }
};

class Fields {
	list<string> fields;
public:
	void setFields(const list<string>& f)
	{
		fields = f;
	}
	void addField(const string f) 
	{
		fields.push_back(f);
	}
	list<string>& getFields(void)
	{
		return fields;
	}
	void appendFields(string& query) 
	{
		list<string>::iterator it;
		for (it = fields.begin();
			it != fields.end(); ++it)
			query = query + " " + *it;
	}
};

class Constraints {
	list<string> constraints;
public:
	void setConstraints(const list<string>& aconstraints)
	{
		constraints = aconstraints;
	}
	void addConstraint(const string c) 
	{
		constraints.push_back(c);
	}
	list<string>& getConstraints(void)
	{
		return constraints;
	}
	void appendConstraints(string& query) 
	{
		list<string>::iterator it;
		for (it = constraints.begin();
			it != constraints.end(); ++it)
			query = query + " " + *it;
	}
};


class Query
{
	Action action;
	Source source;
	Fields fields;
	Constraints constraints;
public:
	void setConstraints(const Constraints& c) { constraints = c; }
	void setSource(const Source& s) { source = s; }
	void setFields(const Fields& f) { fields = f; }
	void setAction(const Action& a) { action = a; }
	string getQuery(void) {
		string query = source.getSource() + " " + action.getAction() + " ";
		fields.appendFields(query);                                                                // qoestion 
		constraints.appendConstraints(query);                           /// what we did not say constraints.getConstraint
		return query;
	}
	void emptyQuery(void) 
	{     // reset the query 
		source.setSource("");
		action.setAction("");                                          
		fields.getFields().clear();
		constraints.getConstraints().clear();
	}
};

class QueryBuilder
{
public:
	virtual void addField(string f) = 0;
	virtual void addConstraint(string c) = 0;
	virtual void setSourceEmployee(void) = 0;
	virtual void setSourceCustomer(void) = 0;
	virtual void setActionView(void) = 0;
	virtual void setActionModify(void) = 0;
	virtual Query getQuery(void) = 0;
	virtual ~QueryBuilder(void) {};
};

// can use one of the  compelete trust or little trust no banned 
//=========================
class CompleteTrustQueryBuilder : public QueryBuilder 
{
	Action action;
	Source source;
	Fields fields;
	Constraints constraints;
public:
	CompleteTrustQueryBuilder(void)
	{
		source.setSource("");
		action.setAction("");
		fields.getFields().clear();
		constraints.getConstraints().clear();
	}
	void addField(string f) override 
	{
		if ((f == "ID") ||
			(f == "ADDRESS") ||
			(f == "FIRST_NAME") ||
			(f == "LAST_NAME") ||
			(f == "BIRTH_DATE")) {
			fields.addField(f);
		}
		else 
		{
			cout << "Field " + f + " is unknown.";
		}
	}
	void addConstraint(const string c) override
	{
		constraints.addConstraint(c);
	}
	void setSourceEmployee(void) override 
	{
		source.setSource("employee");
	}
	void setSourceCustomer(void) override
	{
		source.setSource("customer");
	}
	void setActionView(void) override
	{
		action.setAction("view");
	}
	void setActionModify(void) override 
	{
		action.setAction("modify");
	}
	Query getQuery(void) override 
	{
		Query query;

		if ((action.getAction() == "") || (source.getSource() == "") || (fields.getFields().size() == 0)) 
		{
			cout << "\nCannot create query. Information is missing.\n";
			query.emptyQuery();
		}
		else
		{
			query.setSource(source);
			query.setAction(action);
			query.setFields(fields);
			query.setConstraints(constraints);
		}
		// to clear all data so he second query start frish
		source.setSource("");
		action.setAction("");
		fields.getFields().clear();
		constraints.getConstraints().clear();
		return query;
	}
};
//  === ============///////////////
class littleTrustQueryBuilder : public QueryBuilder
{
	Action action;
	Source source;
	Fields fields;
	Constraints constraints;
public:
	littleTrustQueryBuilder(void)
	{
		source.setSource("");
		action.setAction("");
		fields.getFields().clear();
		constraints.getConstraints().clear();
	}
	void addField(string f) override
	{
		if ((f == "FIRST_NAME") ||
			(f == "LAST_NAME") ||
			(f == "BIRTH_DATE"))
		{
			fields.addField(f);
		}
		// the user cannot access the given field.
		else if ((f == "ID") ||
			(f == "ADDRESS"))
		{
			cout << "\n the user cannot access the given field. " + f + " field\n";
		}
		else
			// the fiels provided is not known/
			cout << "Field " + f + " is unknown.";
	}
	void addConstraint(const string c) override
	{
		constraints.addConstraint(c);
	}
	void setSourceEmployee(void) override
	{
		source.setSource("employee");
	}
	void setSourceCustomer(void) override
	{
		cout << "\nthe user cannot access the sustomer data source.\n";
	}
	void setActionView(void) override
	{
		action.setAction("view");
	}
	void setActionModify(void) override
	{
		cout << "\nthe user cannot modify records.\n";
	}
	Query getQuery(void) override
	{
		Query query;

		if ((action.getAction() == "") || (source.getSource() == "") || (fields.getFields().size() == 0))
		{
			cout << "\nCannot create query. Information is missing.\n";
			query.emptyQuery();
		}
		else
		{
			query.setSource(source);
			query.setAction(action);
			query.setFields(fields);
			query.setConstraints(constraints);
		}
		// to clear all data so he second query start frish
		source.setSource("");
		action.setAction("");
		fields.getFields().clear();
		constraints.getConstraints().clear();
		return query;
	}
};
//============================
class BannedTrustQueryBuilder : public QueryBuilder {
public:
	void addField(string f) override {};
	void addConstraint(string c) override {};
	void setSourceEmployee(void) override {};
	void setSourceCustomer(void) override {};
	void setActionView(void)  override {};
	void setActionModify(void) override {};
	Query getQuery(void) override
	{
		Query query;
		cout << "A banned user cannot access the data";
		query.emptyQuery();
		return query;
	}
};
//================== can use row pointer here or a smart pointer like these in brackets
class QueryDirector
{
	QueryBuilder* builder;    
public:
	QueryDirector(QueryBuilder* newBuilder)
	{ 
		builder = newBuilder;
	}
	void setBuilder(QueryBuilder* newBuilder)
	{
		builder = newBuilder;
	}
	//============
	// here is the ssmart pointer 

	/*class QueryDirector
	{
		shared_ptr<QueryBuilder>builder;
		QueryDirector(shared_ptr<QueryBuilder>newBuilder)   { builder = newBuilder; }
		void setBuilder(shared_ptr<QueryBuilder>newBuilder) { builder = newBuilder; }
	};*/
	// end of smart pointer and the rest are same 

	Query makeQueryGeneral(void)
	{
		cout << "\n**************makeQueryGeneral**************" << endl;
		builder->setSourceEmployee();
		builder->setActionView();
		builder->addField("LAST_NAME");
		builder->addConstraint("UNIQUE");
		Query query = builder->getQuery();
		return query;
	}

	Query makeQueryProtected(void) {
		cout << "\n**************makeQueryProtected**************" << endl;
		builder->setSourceCustomer();
		builder->setActionModify();
		builder->addField("ID");
		builder->addConstraint("UNIQUE");
		Query query = builder->getQuery();
		return query;
	}
};


// improvements instead of if else statments in main function                         // important 


//class trustBaseQueryBuilderFactory
//{
//public:
//	QueryBuilder* getBuilder(const Subject& currSubject)
//	{
//		if (currSubject.getTrustLevel() == TrustLevel::complete)
//		{
//			return  new CompleteTrustQueryBuilder;
//		}
//		else if (currSubject.getTrustLevel() == TrustLevel::little)
//		{
//			return new littleTrustQueryBuilder;
//		}
//		else
//		{
//			return new BannedTrustQueryBuilder;
//		}
//
//
//	}
//};
int main(void)
{
	Subject currSubject = Subject("14.8.9.28");
	//"14.8.9.28" = COMPLETE
	//"14.8.9.29" = LITTLE
	//"14.8.9.30" = BOGUS


	////in stead of row pointer i can use smart pointer here with with the samrt pointer mentioned above 
	//==============================================
	QueryBuilder* builder;
	Query query;

	if (currSubject.getTrustLevel() == TrustLevel::complete) // can get rid of these statments see above class factory functon
	{
		builder = new CompleteTrustQueryBuilder;
	}
	else if (currSubject.getTrustLevel() == TrustLevel::little)
	{
		builder = new littleTrustQueryBuilder;
	}
	else
	{
		builder = new BannedTrustQueryBuilder;
	}

	// ==========================================///

	// see the smart pointer here but off cause i must use smart pointer as mention above
	
	//========end of smart pointer is here
	
	QueryDirector direct(builder);
	query = direct.makeQueryGeneral();
	cout << "\nquery =" << query.getQuery() << endl;
	query = direct.makeQueryProtected();
	cout << "\nquery =" << query.getQuery() << endl;

	delete builder;


	//===========================can use this one 


	/*QueryBuilder* builder;
	Query query;
	builder = new CompleteTrustQueryBuilder;
	QueryDirector direct(builder);
	query = direct.makeQueryProtected();
	cout << "\nquery =" << query.getQuery() << endl;
	query = direct.makeQueryGeneral();
	cout << "\nquery =" << query.getQuery() << endl;

	delete builder;*/

//===================================================================
	//can use this one

	/* QueryBuilder * builder;
	Query query;
	builder = new littleTrustQueryBuilder;
	QueryDirector direct(builder);
	query = direct.makeQueryGeneral();
	cout << "\nquery =" << query.getQuery() << endl;
	query = direct.makeQueryProtected();
	cout << "\nquery =" << query.getQuery() << endl;

	delete builder;*/




//=========================== or this 


	/*QueryBuilder* builder;
	Query query;
	builder = new BannedTrustQueryBuilder;
	QueryDirector direct(builder);
	query = direct.makeQueryGeneral();
	cout << "\nquery =" << query.getQuery() << endl;
	query = direct.makeQueryProtected();
	cout << "\nquery =" << query.getQuery() << endl;

	delete builder;*/


	system("pause");
	return 0;
}