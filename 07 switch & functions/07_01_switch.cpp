#include <iostream>
using namespace std;

int main (){
    int num = 2;

    switch ( num ){
        case 1 : cout << "First" << endl;
                break;
        case 2 : cout << "Second" << endl;
                break;

        default : cout << "It is the default case" << endl;
    }
}




// int main (){
//     char ch = '1';

//     switch ( ch ){
//         case 1 : cout << "First" << endl;
//                 break;

//         case '1' : cout << "Character one" << endl;
//                 break;

//         default : cout << "It is the default case" << endl;
//     }
// }




// int main (){
//     char ch = 'a';

//     switch ( ch ){
//         case 1 : cout << "First" << endl;
//                 break;

//         case '1' : cout << "Character one" << endl;
//                 break;

//         default : cout << "It is the default case" << endl;
//     }
// }



// int main (){
//     char ch = 'a';

//     switch ( ch ){
//         case 1 : cout << "First" << endl;
//                 break;

//         case '1' : cout << "Character one" << endl;
//                 break;

//         //default : cout << "It is the default case" << endl; // DEFAULT is not mandatory
//     }
// }



// int main (){
//     char ch = '1' ;
//     int num = 2;

//     switch ( ch ){
//         case 1 : cout << "First" << endl;
//                 break;

//         case '1' : switch ( num ){
//                         case 2: cout << "The value of num is: " << num << endl;
//                             break; // this break will take you out of this particular switch (not the outer switch)
//                     }
//                 break;

//         default : cout << "It is the default case" << endl;
//     }
// }



// int main (){
//     int num = 1;

//     switch ( 2*num ){
//         case 1 : cout << "First" << endl;
//                 break;
//         case 2 : cout << "Second" << endl;
//                 break;

//         default : cout << "It is the default case" << endl;
//     }
// }
