#include<iostream>
#include<string>
using namespace std;
string xor_s(string s1,string s2){
    string ans="";
    for(int i=1;s1[i]!='\0';i++){
        if(s1[i]==s2[i]){
            ans = ans + '0';
        }
        else{
            ans = ans + '1';
        }
    }
    return ans;
}
string div(string dividend,string divisor,int len){
    int index = divisor.length()-1;
    string ans="";
    for(int i=0;i<index;i++){
        ans=ans+dividend[i];
    }
    while(len--){
        ans = ans+dividend[index++];
        if(ans[0]=='1'){
            ans = xor_s(ans,divisor);
        }
        else{
            ans = xor_s(ans,"00000000000000000");
        }
    }
    return ans;
}
int main(){
    string divisor = "10001000000100001";
    string dividend;
    cout<<"Enter data\n";
    cin>>dividend;
    int len = dividend.length();
    string c_dividend = dividend;
    cout<<"Generating polynomial is "<<divisor<<"\n";
    for(int i=1;i<divisor.length();i++){
        dividend = dividend+'0';
    }
    cout<<"Modified data is "<<dividend<<"\n";
    string rem = div(dividend,divisor,len);
    cout<<"CRC checksum is "<<rem<<"\n";
    cout<<"Final Code word is "<<c_dividend<<rem<<"\n";
    cout<<"Test Error Detection 0<No> 1<Yes>\n";
    int choice;
    cin>>choice;
    if(choice==0){
        cout<<"No error detected\n";
        cout<<"Checksum:"<<div(c_dividend+rem,divisor,len)<<"\n";
    }
    else{
        cout<<"Enter position where error is to be inserted\n";
        int error;
        cin>>error;
        string t_crc = c_dividend+rem;
        if(t_crc[error-1]=='1'){
            t_crc[error-1]='0';
        }
        else{
            t_crc[error-1]='1';
        }
        cout<<"Erroneous data "<<t_crc<<"\n";
        string ck = div(t_crc,divisor,len);
        cout<<"CRC Checksum:"<<ck<<"\n";
        cout<<"Error detected\n";
    }
    return 0;
}
