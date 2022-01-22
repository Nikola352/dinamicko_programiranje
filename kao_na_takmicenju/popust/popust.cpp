#include <bits/stdc++.h>
using namespace std;

struct Offer{
    vector<int> prodCodes, prodNum;
    int price;
};

string getKey(const vector<int>& quantity){
    string res = to_string(quantity.size()) + ": ";
    for(int q : quantity)
        res += to_string(q) + ", ";
    return res;
}

unordered_map<string, int> mem;

int calc(vector<int>& quantity, int n, const vector<int>& price, const vector<Offer>& offers){
    string key = getKey(quantity);
    if(mem.find(key) != mem.end())
        return mem[key];

    bool sold = true;
    for(int i=0; i<n; i++){
        if(quantity[i] > 0){
            sold = false;
            break;
        }
    }

    if(sold){
        mem[key] = 0;
        return 0;
    }

    int res = 0;
    for(int i=0; i<n; i++)
        res += quantity[i] * price[i];

    for(const Offer& offer : offers){
        bool possible = true;
        for(int i=0; i<offer.prodCodes.size(); i++){
            quantity[offer.prodCodes[i]] -= offer.prodNum[i];
            if(quantity[offer.prodCodes[i]] < 0)
                possible = false;
        }

        if(possible)
            res = min(res, calc(quantity, n, price, offers) + offer.price);

        for(int i=0; i<offer.prodCodes.size(); i++)
            quantity[offer.prodCodes[i]] += offer.prodNum[i];
    }

    mem[key] = res;
    return res;
}


int main()
{
    ifstream in("input.txt"), offIn("offer.txt");
    ofstream out("output.txt");

    int n; 
    in >> n;
    
    unordered_map<int,int> code;    
    vector<int> price(n), quantity(n); 

    for(int i=0; i<n; i++){
        int c;
        in >> c >> quantity[i] >> price[i];
        code[c] = i;
    }

    int noff; 
    offIn >> noff;

    vector<Offer> offers(noff);

    for(int i=0; i<noff; i++){
        int np; offIn >> np;
        for(int j=0; j<np; j++){
            int c, num; 
            offIn >> c >> num;
            offers[i].prodCodes.push_back(code[c]);
            offers[i].prodNum.push_back(num);
        }
        offIn >> offers[i].price;
    }

    mem.clear();

    out << calc(quantity, n, price, offers) << '\n';

    return 0;
}