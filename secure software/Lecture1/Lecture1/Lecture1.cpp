#include <limits.h>
#include <iostream>
using namespace std;

// tutorial 1 question (a) unsigned integer

void unsignedWrap()
{
    unsigned int ui_a=UINT_MAX;

    cout<<UINT8_MAX<<endl;
    cout<<UINT_MAX<<endl;
    cout<<UINT16_MAX<<endl;
    cout<<UINT32_MAX<<endl;
    cout<<"********"<<endl;
     cout<<"********"<<endl;

    cout<<"the integer at max value is = "<<ui_a<<endl;
    ui_a+=1;
    cout<<" after adding 1, the value is  = "<<ui_a<<endl;
    cout<<"======================================"<<endl;}

void unsigned_Wrap()
{
unsigned int ui_b= 0;
   cout<<"the integer at min value is = "<<ui_b<<endl;
   ui_b-=1;
   cout<<" after adding 1, the value is  = "<<ui_b<<endl;
    cout<<"======================================"<<endl;}

// tutorial 1 question (b) faulty one

void faultyAddThem(unsigned int ui_a, unsigned int ui_b)
{
    cout<<"befor adding we have "<<ui_a<<"  and  "<<ui_b<<endl;
    unsigned int ui_sum = ui_a + ui_b;
    cout<<" afetr adding , we have  "<< ui_sum<<endl;
    cout<<"======================================"<<endl;

}

// tutorial 1 question (b)  better one

void betterAddThemPerCkeck(uint16_t ui_a, uint16_t ui_b)
{
    uint16_t ui_sum;
    cout<<"befor adding we have "<<ui_a<<"  and  "<<ui_b<<endl;

if (UINT16_MAX - ui_a < ui_b)
{
    cout<<"sorry can not do that "<<endl;

} else
       {
          ui_sum = ui_a + ui_b;
          cout<<"the answer is = "<<ui_sum<<endl;
       }

    cout<<"======================================"<<endl;

}
// tutorial 1 question (C)  post check better one

void  betterAddThemPostCheck(uint16_t ui_a, uint16_t ui_b)
{
    cout<<"befor adding we have "<<ui_a<<"  and  "<<ui_b<<endl;
    uint16_t ui_sum = ui_a + ui_b;
    cout<<"aftr adding them er got = "<<ui_sum<<endl;

if (ui_sum < ui_a)
{
    cout<<"A wrap is occured "<<endl;

} else
{
          cout<< "this went well"<<endl;
}
    cout<<"======================================"<<endl;

}


// tutorial 1 question ( D) Per Subtraction

void PerSubtaction(uint16_t ui_a, uint16_t ui_b)
{
    cout<<" befor we subtract  we have "<<ui_a<<" and "<<ui_b<<endl;

    uint16_t uiSum = ui_a - ui_b;
  cout<<" after we subtract  we got "<< uiSum<<endl;
    cout<<"======================================"<<endl;

}

// subtraction better one
void Per_subtraction(uint16_t ui_a, uint16_t ui_b)
{
    uint16_t ui_sum;
    cout<<"befor subtraction we have "<<ui_a<<"  and  "<<ui_b<<endl;

    ////// question why we used like that
    if (ui_a < ui_b)
{
    cout<<"sorry can not do that "<<endl;

} else
       {
          ui_sum = ui_a - ui_b;
          cout<<"the answer is = "<<ui_sum<<endl;
       }

    cout<<"======================================"<<endl;
    }

// questio 0ne (D) post subtraction
void Post_subtraction(uint16_t ui_a, uint16_t ui_b)
{
    cout<<"befor subtraction we have "<<ui_a<<"  and  "<<ui_b<<endl;
    uint16_t ui_sum = ui_a - ui_b;
    cout<<"after subtraction we have "<<ui_sum <<endl;
    /// why    >
    if (ui_sum > ui_a)
{
    cout<<"A rawp is occured "<<endl;

} else
       {

          cout<<"no issue happened  " <<endl;
       }

    cout<<"======================================"<<endl;
    }



// tutorial one question( e ) per multiplication

void PerMultiplication(uint16_t ui_a, uint16_t ui_b)
{
    cout<<" befor we multiplying  we have "<<ui_a<<" and "<<ui_b<<endl;

    uint16_t uiSum = ui_a * ui_b;
  cout<<" after we multiplied  we got "<< uiSum<<endl;
    cout<<"======================================"<<endl;

}

// multiplication better one
void Per_Multiplication(uint16_t ui_a, uint16_t ui_b)
{
    uint16_t ui_sum;
    cout<<"befor Multiplication we have "<<ui_a<<"  and  "<<ui_b<<endl;

    ////// question why we used like that /// how shall i do that multiplication
    if (ui_a < ui_b)// (UINT16_MAX/ui_b > ui_a)
{
    cout<<"sorry can not do that "<<endl;

} else
       {
          ui_sum = ui_a * ui_b;
          cout<<"the answer is = "<<ui_sum<<endl;
       }

    cout<<"======================================"<<endl;
    }

// questio 0ne (e) post subtraction
void Permultiplication(uint16_t ui_a, uint16_t ui_b)
{
    cout<<"befor ultiplication we have "<<ui_a<<"  and  "<<ui_b<<endl;
    uint16_t ui_sum = ui_a * ui_b;
    cout<<"after ultiplication we have "<<ui_sum <<endl;
    //// question why   >
    if (ui_sum > ui_a)
{
    cout<<"A rawp is happened"<<endl;

} else
       {

          cout<<"every thing is fine " <<endl;
       }

    cout<<"======================================"<<endl;
    }

int main()
{
    unsignedWrap();
    unsigned_Wrap();

    faultyAddThem(4000000000, 1000000000);
    betterAddThemPerCkeck(40000, 40000);

    //betterAddThemPerCkeck(4000, 4000);
   // betterAddThemPostCheck(40000, 40000);
   // betterAddThemPostCheck(4000, 4000);
    //PerSubtaction(40000,30000);
    //Per_subtraction(30000,40000);// what will happen if I chancged the order
    //Post_subtraction(50000,20000);
    //PerMultiplication(3000,3000);
    //Per_Multiplication(2000,1000);
    //Permultiplication(2000,1000);
    return 0;
}




//
//
////tutorial 1 part two signed integer ( a )
//void signedWrap()
//{
//    signed int si_a = INT_MAX;
//
//    cout << INT8_MAX << endl;
//    cout << INT_MAX << endl;
//    cout << INT16_MAX << endl;
//    cout << INT32_MAX << endl;
//    cout << "**********" << endl;
//    cout << "********" << endl;
//
//    cout << "the integer at max value is = " << si_a << endl;
//    si_a += 1;
//    cout << " after adding 1, the value is  = " << si_a << endl;
//    cout << "======================================" << endl;
//}
//
//void signed_Wrap()
//{
//    signed int si_a = INT_MIN;
//    cout << "the integer at max value is = " << si_a << endl;
//    si_a -= 1;
//    cout << " after adding 1, the value is  = " << si_a << endl;
//    cout << "======================================" << endl;
//}
//
//
////tutorial 1 part two signed integer ( b )
//void singedFaultyAddThem(signed int si_a, signed int si_b)
//{
//    cout << "befor adding we have " << si_a << "  and  " << si_b << endl;
//    signed int si_sum = si_a + si_b;
//    cout << " afetr adding , we have  " << si_sum << endl;
//    cout << "======================================" << endl;
//
//}
//
//// tutorial 1 question (b) singed better one
//
//void singedBetterAddThemPerCkeck(int16_t si_a, int16_t si_b)
//{
//    int16_t si_sum;
//    cout << "befor adding we have " << si_a << "  and  " << si_b << endl;
//
//    if ((si_b > 0 && si_a > (INT16_MAX - si_b)) ||
//        (si_b < 0 && si_a < INT16_MIN - si_a))
//
//    {
//        cout << "sorry can not do that " << endl;
//
//    }
//    else
//    {
//        si_sum = si_a + si_b;
//        cout << "the answer is = " << si_sum << endl;
//    }
//    cout << "======================================" << endl;
//
//}
//
//
//
//// tutorial 1 question ( D )  singed  Subtraction
//
//void Subtaction(int16_t si_a, int16_t si_b)
//{
//    cout << " befor we subtract  we have " << si_a << " and " << si_b << endl;
//
//    uint16_t uiSum = si_a - si_b;
//    cout << " after we subtract  we got " << uiSum << endl;
//    cout << "======================================" << endl;
//
//}
//
//// subtraction better one
//void Per_subtraction(int16_t si_a, int16_t si_b)
//{
//    int16_t si_sum;
//    cout << "befor subtraction we have " << si_a << "  and  " << si_b << endl;
//
//    if (((si_b > 0 && si_a < INT_MIN + si_b) ||
//        (si_b < 0 && si_a > INT_MAX + si_b)))
//    {
//        cout << "sorry can not do that " << endl;
//
//    }
//    else
//    {
//        si_sum = si_a - si_b;
//        cout << "the answer is = " << si_sum << endl;
//    }
//
//    cout << "======================================" << endl;
//}
//
//// question 2 (  d )
//void singedFaultyMultiolication(signed int si_a, signed int si_b)
//{
//    cout << "befor multiplying them we have " << si_a << "  and  " << si_b << endl;
//    signed int si_sum = si_a * si_b;
//    cout << " afetr multiplying , we have  " << si_sum << endl;
//    cout << "======================================" << endl;
//
//}
//
//void PerMultilplication(signed int si_a, signed int si_b)
//{
//    signed int result;
//    if (si_a > 0) /* si_a is positive */
//    {
//        if (si_b > 0)
//        {/* si_a and si_b are positive */
//            if (si_a > (INT_MAX / si_b))
//            {
//                cout << " can not do that " << endl;
//            }
//        }
//        else
//        { /* si_a positive, si_b nonpositive */
//            if (si_b < (INT_MIN / si_a)) {
//                cout << " can not do that " << endl;
//            }
//        } /* si_a positive, si_b nonpositive */
//    }
//    else
//    { /* si_a is nonpositive */
//        if (si_b > 0)
//        { /* si_a is nonpositive, si_b is positive */
//            if (si_a < (INT_MIN / si_b)) {
//                cout << " can not do that " << endl;
//            }
//        }
//        else { /* si_a and si_b are nonpositive */
//            if ((si_a != 0) && (si_b < (INT_MAX / si_a)))
//            {
//                cout << " can not do that " << endl;
//            }
//        } /* End if si_a and si_b are nonpositive */
//    } /* End if si_a is nonpositive */
//
//    result = si_a * si_b;
//    cout << " the answer is this = " << result << endl;
//}
//
//
//// tutorial 1 part 2 division
//
//
//void singedDivision(signed long si_a, signed long si_b)
//{
//    cout << "befor dividing  we have " << si_a << "  and  " << si_b << endl;
//    signed long result;
//    if (si_b == 0)
//    {
//        cout << "can not do that " << endl;
//    }
//    else
//    {
//        result = si_a / si_b;
//    }
//    cout << " afetr dividing  , we have  " << result << endl;
//    cout << "======================================" << endl;
//
//}
//
//void singedDivisionPerCheck(signed long si_a, signed long si_b)
//{
//    cout << "befor dividing  we have " << si_a << "  and  " << si_b << endl;
//    signed long result;
//    if ((si_b == 0) || ((si_a == LONG_MIN) && (si_b == -1)))
//    {
//
//        cout << "can not do that " << endl;
//    }
//    else
//    {
//        result = si_a / si_b;
//    }
//    cout << " afetr dividing  , we have  " << result << endl;
//    cout << "======================================" << endl;
//
//}
//
//// multiplication better one
//void Per_Multiplication(uint16_t ui_a, uint16_t ui_b)
//{
//    uint16_t ui_sum;
//    cout << "befor Multiplication we have " << ui_a << "  and  " << ui_b << endl;
//
//    ////// question why we used like that /// how shall i do that multiplication
//    if (ui_a < ui_b)// (UINT16_MAX/ui_b > ui_a)
//    {
//        cout << "sorry can not do that " << endl;
//
//    }
//    else
//    {
//        ui_sum = ui_a * ui_b;
//        cout << "the answer is = " << ui_sum << endl;
//    }
//
//    cout << "======================================" << endl;
//}
//
//
//
///*int main()
//{
//    signedWrap();
//    signed_Wrap();
//    //singedFaultyAddThem(1500000000,1500000000);
//    //singedBetterAddThemPerCkeck(30000,30000);
//    // singedBetterAddThemPerCkeck(3000,2000);
//   // Subtaction(20000,10000);
//   // Per_subtraction(30000,30000);
//    //singedFaultyMultiolication(1000,1000);
//    //PerMultilplication(30000,20000);
//    //singedDivision(70000,0);
//    //singedDivisionPerCheck(50000,0);
//    Per_Multiplication(30000, 2);
//   return 0;
//}*/
