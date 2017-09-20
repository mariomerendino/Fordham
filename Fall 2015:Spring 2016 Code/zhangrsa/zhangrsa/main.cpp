
Mail
COMPOSE
Labels
Inbox (2)
Starred
Important
Sent Mail
Drafts (5)
Circles
Notes
More
Chat
Mario Merendino

Search people...
alaub2
Alexander Elnabli
Alyssa Marotta
Anarlyn Nunez
Andrew Marinaccio
Anwar Kadirov
Ashley Katusa
Christine Papadakis Kanaris
Justin Lesko
Martin Bartoszewicz

Move to Inbox More
3 of 32

Print all In new window
CISC2100: RSA code
Inbox
x

Xiaolan Zhang
AttachmentsNov 23

to Frank, James, barriagb, Dennis, Ryan, Jeffrey, Derek, Garrick, Britni, me, Liam, David, Patrick, Palma
Dear all,

Please find in the attachment solution to today's lab.



On Sun, Nov 22, 2015 at 10:14 AM, Xiaolan Zhang <xzhang@fordham.edu> wrote:
Dear all,

We will meet in the lab tomorrow, to work on some programming practice related to RSA.

Thanks!

Attachments area
Preview attachment RSA.cpp

C++
RSA.cpp

Click here to Reply, Reply to all, or Forward
Using 0.76 GB
Program Policies
Powered by Google
Last account activity: 25 minutes ago
Details
People (14)
Xiaolan Zhang
Add to circles

Show details


#include <iostream>
#include <assert.h>
using namespace std;

/* Codes related to RSA */

/* return the gcd of A and B
 * Assumping: A>B>0
 */
int gcd(int A, int B)
{
    int r;
    
    assert (A>=B && A>=0 && B>=0);
    
    if (B==0)
        return A;
    else{
        r = A%B;
        return gcd (B, r);
    }
}


/* return the gcd of A and B
 * A>B>0
 * d = As+Bt;
 */
int gcd_extended(int A, int B, int & s, int & t)
{
    int r,q;
    int s1,t1;
    int d;
    
    assert (A>=B && A>=0 && B>=0);
    
    if (B==0)
    {
        s = 1;
        t = 0;
        return A;
    }
    else{
        r = A%B;
        q = A/B;
        d = gcd_extended (B, r, s1, t1);
        s = t1;
        t = s1-q*t1;
        return d;
    }
}

/* return the gcd of A and B
 * A>B>0
 */
int gcd_loop(int A, int B)
{
    int r;
    int a, b;
    
    
    assert (A>=B && A>=0 && B>=0);
    
    a = A;
    b = B;
    
    while (b>0)
    {
        r = a%b;
        a = b;
        b = r;
        //return gcd (B, r);
    }
    return a;
}


/* return the gcd of A and B
 * A>B>0
 */
int gcd_loop_extended(int A, int B, int & s, int & t)
{
    int r,q;
    int a, b;
    int u,v,newu,newv;
    
    cout<< "calling "<<A<<","<<B<<endl;
    assert (A>=B && A>=0 && B>=0);
    
    //precondition: a = sA+tB, b=uA+vB
    a = A;
    b = B;
    s = 1;
    t = 0;
    u = 0;
    v = 1;
    
    while (b>0)
    {
        //loop invariant: a = sA+tB and b = uA+vB
        r = a%b;
        q = a/b;
        
        a = b;
        b = r;
        
        newu = s-u*q;
        newv = t-v*q;
        s = u;
        t = v;
        u = newu;
        v = newv;
    }
    // postcondition, a=gcd(A,B)=sA+tB, b =0;
    return a;
}

/* return the int value that is multiplictaive inverse of m modulo n */
/* ret*m mod n = 1 */
int MultiplicativeInverse (int m, int n)
{
    int s, t, d;
    
    d = gcd_loop_extended(n, m, s, t);
    //upon return from gcd, d=sn+tm;
    assert (d==1);
    return t;
    
}

// using public key <n,e> to encode a message m
int encode (int m, int n, int e)
{
    int exp=1;
    for (int i=0;i<e;i++)
        exp = (exp*m) % n;
    return exp;
}


// using private key <n,d> to decore a cipher code c
int decode (int c, int n, int d)
{
    int exp=1;
    for (int i=0;i<d;i++)
        exp = (exp*m) % n;
    return exp;
}

int main()
{
    int larger, smaller;
    int s,t;
    
    
     cout <<"Enter two integers, the bigger one first:";
     cin >> larger >> smaller;
     cout <<"gcd of the two numbers is" << gcd (larger, smaller)<<endl;
     cout <<"gcd of the two numbers is" << gcd_extended (larger, smaller,s,t)<<endl;
     cout <<"s="<<s<<endl;
     cout <<"t="<<t<<endl;
     cout <<"gcd of the two numbers is" << gcd_loop (larger, smaller)<<endl;
     cout <<"gcd of the two numbers is" << gcd_loop_extended (larger, smaller,s,t)<<endl;
     cout <<"s="<<s<<endl;
     cout <<"t="<<t<<endl;
     
     
     //Find multiplicative inverse
     int n,a;
     cout <<"Enter n";
     cin >> n;
     cout <<"Enter a";
     cin >> a;
     if (gcd_loop_extended (n,a,s,t)==1)
     {
     cout <<"they are coprime, i.e.,gcd is 1"<<endl;
     cout <<a<<"'s multiplicative inverse moduolo "<< n <<" is" << t%n <<endl;
     cout <<"verifify: " <<a<<"*"<<t<<"%"<<n<<"=" <<a*t %n << endl;
     }
    
    
    //RSA using public key <n,e>
    //n=713=23*31, e=43
    int n=713;
    int e=43;
    int phin = 22*30;
    int d;
    
    d = MultiplicativeInverse (e, phin);
    cout <<"d*e % phin="<<t*e % phin <<endl;
    
    
    cout <<"Enter a char to encode";
    char ch;
    cin >> ch;
    int cipher = encode ((int)ch, n, e);
    cout <<"cipher code" << cipher<<endl;
    
    //Decode use d 
    int message = decode (cipher, n, d);
    cout <<"Decoded: " << (char)message<<endl;
    
    
}