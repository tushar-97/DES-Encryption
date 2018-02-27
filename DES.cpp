#include<iostream>
#include<iomanip>
#include<string>
#include<bitset>
#include<sstream>

using namespace std;

string to_binary(int n)
{
    switch(n)
    {
        case 0: return "0000";
        case 1: return "0001";
        case 2: return "0010";
        case 3: return "0011";
        case 4: return "0100";
        case 5: return "0101";
        case 6: return "0110";
        case 7: return "0111";
        case 8: return "1000";
        case 9: return "1001";
        case 10: return "1010";
        case 11: return "1011";
        case 12: return "1100";
        case 13: return "1101";
        case 14: return "1110";
        case 15: return "1111";
    }
}
int to_decimal(string str){
    if(str=="00") return 0;
    else if(str=="01") return 1;
    else if(str=="10") return 2;
    else if(str=="11") return 3;

    else if (str=="0000") return 0;
    else if (str=="0001") return 1;
    else if (str=="0010") return 2;
    else if (str=="0011") return 3;
    else if (str=="0100") return 4;
    else if (str=="0101") return 5;
    else if (str=="0110") return 6;
    else if (str=="0111") return 7;
    else if (str=="1000") return 8;
    else if (str=="1001") return 9;
    else if (str=="1010") return 10;
    else if (str=="1011") return 11;
    else if (str=="1100") return 12;
    else if (str=="1101") return 13;
    else if (str=="1110") return 14;
    else if (str=="1111") return 15;
}

string to_hex(string str){
    if(str=="0000") return "0";
    else if (str=="0001") return "1";
    else if (str=="0010") return "2";
    else if (str=="0011") return "3";
    else if (str=="0100") return "4";
    else if (str=="0101") return "5";
    else if (str=="0110") return "6";
    else if (str=="0111") return "7";
    else if (str=="1000") return "8";
    else if (str=="1001") return "9";
    else if (str=="1010") return "A";
    else if (str=="1011") return "B";
    else if (str=="1100") return "C";
    else if (str=="1101") return "D";
    else if (str=="1110") return "E";
    else if (str=="1111") return "F";
}

string convert_bin(char c)
{
    switch(toupper(c))
    {
        case '0': return "0000";
        case '1': return "0001";
        case '2': return "0010";
        case '3': return "0011";
        case '4': return "0100";
        case '5': return "0101";
        case '6': return "0110";
        case '7': return "0111";
        case '8': return "1000";
        case '9': return "1001";
        case 'A': return "1010";
        case 'B': return "1011";
        case 'C': return "1100";
        case 'D': return "1101";
        case 'E': return "1110";
        case 'F': return "1111";
    }
}

int main(){

  string plain00,key00,key,plain,l1,r1,str,a,b;
  char c;
  int i,j,k,temp1,temp2,flag;
  cin>>key00>>plain00;

  int PC1[56] = {
   57, 49, 41, 33, 25, 17,  9,
    1, 58, 50, 42, 34, 26, 18,
   10,  2, 59, 51, 43, 35, 27,
   19, 11,  3, 60, 52, 44, 36,
   63, 55, 47, 39, 31, 23, 15,
    7, 62, 54, 46, 38, 30, 22,
   14,  6, 61, 53, 45, 37, 29,
   21, 13,  5, 28, 20, 12,  4
  };

  int PC2[48] = {
    14, 17, 11, 24,  1,  5,
    3, 28, 15,  6, 21, 10,
    23, 19, 12,  4, 26,  8,
    16,  7, 27, 20, 13,  2,
    41, 52, 31, 37, 47, 55,
    30, 40, 51, 45, 33, 48,
    44, 49, 39, 56, 34, 53,
    46, 42, 50, 36, 29, 32
  };

  int IP[64] = {
    58, 50, 42, 34, 26, 18, 10,  2,
    60, 52, 44, 36, 28, 20, 12,  4,
    62, 54, 46, 38, 30, 22, 14,  6,
    64, 56, 48, 40, 32, 24, 16,  8,
    57, 49, 41, 33, 25, 17,  9,  1,
    59, 51, 43, 35, 27, 19, 11,  3,
    61, 53, 45, 37, 29, 21, 13,  5,
    63, 55, 47, 39, 31, 23, 15,  7};

  int Expansion[48] = {
    32,  1,  2,  3,  4,  5,  4,  5,
     6,  7,  8,  9,  8,  9, 10, 11,
    12, 13, 12, 13, 14, 15, 16, 17,
    16, 17, 18, 19, 20, 21, 20, 21,
    22, 23, 24, 25, 24, 25, 26, 27,
    28, 29, 28, 29, 30, 31, 32,  1};

  int Sbox[8][4][16] = {
     {
     {14,  4, 13,  1,  2, 15, 11,  8,  3, 10,  6, 12,  5,  9,  0,  7},
     { 0, 15,  7,  4, 14,  2, 13,  1, 10,  6, 12, 11,  9,  5,  3,  8},
     { 4,  1, 14,  8, 13,  6,  2, 11, 15, 12,  9,  7,  3, 10,  5,  0},
     {15, 12,  8,  2,  4,  9,  1,  7,  5, 11,  3, 14, 10,  0,  6, 13},
     },

     {
     {15,  1,  8, 14,  6, 11,  3,  4,  9,  7,  2, 13, 12,  0,  5, 10},
     { 3, 13,  4,  7, 15,  2,  8, 14, 12,  0,  1, 10,  6,  9, 11,  5},
     { 0, 14,  7, 11, 10,  4, 13,  1,  5,  8, 12,  6,  9,  3,  2, 15},
     {13,  8, 10,  1,  3, 15,  4,  2, 11,  6,  7, 12,  0,  5, 14,  9},
     },

     {
     {10,  0,  9, 14,  6,  3, 15,  5,  1, 13, 12,  7, 11,  4,  2,  8},
     {13,  7,  0,  9,  3,  4,  6, 10,  2,  8,  5, 14, 12, 11, 15,  1},
     {13,  6,  4,  9,  8, 15,  3,  0, 11,  1,  2, 12,  5, 10, 14,  7},
     { 1, 10, 13,  0,  6,  9,  8,  7,  4, 15, 14,  3, 11,  5,  2, 12},
     },

     {
     { 7, 13, 14,  3,  0,  6,  9, 10,  1,  2,  8,  5, 11, 12,  4, 15},
     {13,  8, 11,  5,  6, 15,  0,  3,  4,  7,  2, 12,  1, 10, 14,  9},
     {10,  6,  9,  0, 12, 11,  7, 13, 15,  1,  3, 14,  5,  2,  8,  4},
     { 3, 15,  0,  6, 10,  1, 13,  8,  9,  4,  5, 11, 12,  7,  2, 14},
     },

     {
     { 2, 12,  4,  1,  7, 10, 11,  6,  8,  5,  3, 15, 13,  0, 14,  9},
     {14, 11,  2, 12,  4,  7, 13,  1,  5,  0, 15, 10,  3,  9,  8,  6},
     { 4,  2,  1, 11, 10, 13,  7,  8, 15,  9, 12,  5,  6,  3,  0, 14},
     {11,  8, 12,  7,  1, 14,  2, 13,  6, 15,  0,  9, 10,  4,  5,  3},
     },

     {
     {12,  1, 10, 15,  9,  2,  6,  8,  0, 13,  3,  4, 14,  7,  5, 11},
     {10, 15,  4,  2,  7, 12,  9,  5,  6,  1, 13, 14,  0, 11,  3,  8},
     { 9, 14, 15,  5,  2,  8, 12,  3,  7,  0,  4, 10,  1, 13, 11,  6},
     { 4,  3,  2, 12,  9,  5, 15, 10, 11, 14,  1,  7,  6,  0,  8, 13},
     },

     {
     { 4, 11,  2, 14, 15,  0,  8, 13,  3, 12,  9,  7,  5, 10,  6,  1},
     {13,  0, 11,  7,  4,  9,  1, 10, 14,  3,  5, 12,  2, 15,  8,  6},
     { 1,  4, 11, 13, 12,  3,  7, 14, 10, 15,  6,  8,  0,  5,  9,  2},
     { 6, 11, 13,  8,  1,  4, 10,  7,  9,  5,  0, 15, 14,  2,  3, 12},
     },

     {
     {13,  2,  8,  4,  6, 15, 11,  1, 10,  9,  3, 14,  5,  0, 12,  7},
     { 1, 15, 13,  8, 10,  3,  7,  4, 12,  5,  6, 11,  0, 14,  9,  2},
     { 7, 11,  4,  1,  9, 12, 14,  2,  0,  6, 10, 13, 15,  3,  5,  8},
     { 2,  1, 14,  7,  4, 10,  8, 13, 15, 12,  9,  0,  3,  5,  6, 11},
     },};

  int Pbox[32] = {
      16,  7, 20, 21, 29, 12, 28, 17,
       1, 15, 23, 26,  5, 18, 31, 10,
       2,  8, 24, 14, 32, 27,  3,  9,
      19, 13, 30,  6, 22, 11,  4, 25
  };

  for(i=0;i<64;i++){
    key+=convert_bin(key00[i]);
    }

  int key0[56];
  for(i=0;i<56;i++){
    j=PC1[i];
    key0[i]=key[j-1]-'0';
  }

  for(i=0;i<64;i++){
    plain+=convert_bin(plain00[i]);
    }

  int plain0[64];
    for(i=0;i<64;i++){
      j=IP[i];
      plain0[i]=plain[j-1]-'0';
    }

    int l0[32],r0[32];
    for(i=0;i<32;i++){
      l0[i]=plain0[i];
      r0[i]=plain0[i+32];
    }



  int c0[28],d0[28];
  for(i=0;i<28;i++){
    c0[i]=key0[i];
    d0[i]=key0[i+28];
  }

  int ckey[17][28];

  for(int i=1;i<=16;i++){
      if(i==1){
        temp1=c0[0];
        for(j=1;j<28;j++)
          ckey[i][j-1]=c0[j];
        ckey[i][27]=temp1;
      }
      else if(i==2 || i==9 || i==16){
        temp1=ckey[i-1][0];
        for(j=1;j<28;j++)
          ckey[i][j-1]=ckey[i-1][j];
        ckey[i][27]=temp1;
      }
      else{
        temp1=ckey[i-1][0];
        temp2=ckey[i-1][1];
        for(j=2;j<28;j++)
          ckey[i][j-2]=ckey[i-1][j];
        ckey[i][26]=temp1;
        ckey[i][27]=temp2;
      }
  }

  int dkey[17][28];

  for(int i=1;i<=16;i++){
      if(i==1){
        temp1=d0[0];
        for(j=1;j<28;j++)
          dkey[i][j-1]=d0[j];
        dkey[i][27]=temp1;
      }
      else if(i==2 || i==9 || i==16){
        temp1=dkey[i-1][0];
        for(j=1;j<28;j++)
          dkey[i][j-1]=dkey[i-1][j];
        dkey[i][27]=temp1;
      }
      else{
        temp1=dkey[i-1][0];
        temp2=dkey[i-1][1];
        for(j=2;j<28;j++)
          dkey[i][j-2]=dkey[i-1][j];
        dkey[i][26]=temp1;
        dkey[i][27]=temp2;
      }
  }

  int finalkey[17][48];

  for(i=1;i<=16;i++){
    for(j=0;j<48;j++){
      if(PC2[j]<29){
        finalkey[i][j]=ckey[i][PC2[j]-1];
      }
      else{
        finalkey[i][j]=dkey[i][PC2[j]-29];
      }
    }
  }


  for(i=1;i<=16;i++){
    for(j=0;j<12;j++){
      str="";
      for(k=0;k<4;k++){
        c = (char)(finalkey[i][j*4+k] + 48);
        str +=c;
        if(k==3) cout<<to_hex(str);
        }
      }
      cout<<endl;
    }

    int r48[48];
    for(i=0;i<48;i++){
      j=Expansion[i];
      r48[i]=r0[j-1] ^ finalkey[1][i];
    }

    str="";
  for(i=0;i<8;i++){
    a="";
    b="";
    a+=(char)r48[i*6+0]+48;
    a+=(char)r48[i*6+5]+48;
    b+=(char)r48[i*6+1]+48;
    b+=(char)r48[i*6+2]+48;
    b+=(char)r48[i*6+3]+48;
    b+=(char)r48[i*6+4]+48;

    str+=to_binary(Sbox[i][to_decimal(a)][to_decimal(b)]);
  }

  int r32[32],rf32[32];
  for(i=0;i<32;i++){
    r32[i]=(int)str[i]-'0';
  }

  for(i=0;i<32;i++){
    rf32[i]=r32[Pbox[i]-1];
  }

  int r11[32];
  for(i=0;i<32;i++){
    r11[i]=rf32[i]^l0[i];
  }

  for(i=0;i<8;i++){
    str="";
    for(j=0;j<4;j++){
      c = (char)(r0[i*4+j] + 48);
      str +=c;
      if(j==3) cout<<to_hex(str);
      }
    }

    for(i=0;i<8;i++){
      str="";
      for(j=0;j<4;j++){
        c = (char)(r11[i*4+j] + 48);
        str +=c;
        if(j==3) cout<<to_hex(str);
        }
      }

  return 0;
}
