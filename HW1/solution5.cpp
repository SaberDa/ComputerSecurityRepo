#include <iostream>
#include <vector>

using namespace std;

const int S0[4][4] = {
	{ 2,1,2,1 },
	{ 2,3,3,1 },
	{ 2,3,2,2 },
	{ 2,3,1,1 }
};

const int S1[4][4] = { 
	{ 1,2,3,2 },
	{ 1,2,1,2 },
	{ 2,2,3,0 },
	{ 3,2,3,1 }
};


vector<int> permute_10(vector<int>& a) {

    vector<int> res;
    res.push_back(a[2]);
    res.push_back(a[4]);
    res.push_back(a[1]);
    res.push_back(a[6]);
    res.push_back(a[3]);
    res.push_back(a[9]);
    res.push_back(a[0]);
    res.push_back(a[8]);
    res.push_back(a[7]);
    res.push_back(a[5]);

    return res;

}

vector<int> leftShiftKey_1(vector<int>& a) {

    vector<int> res;
    res.push_back(a[1]);
    res.push_back(a[2]);
    res.push_back(a[3]);
    res.push_back(a[4]);
    res.push_back(a[0]);
    res.push_back(a[6]);
    res.push_back(a[7]);
    res.push_back(a[8]);
    res.push_back(a[9]);
    res.push_back(a[5]);

    return res;

}

vector<int> permute_8(vector<int>& a) {

    vector<int> res;
    res.push_back(a[5]);
    res.push_back(a[2]);
    res.push_back(a[6]);
    res.push_back(a[3]);
    res.push_back(a[7]);
    res.push_back(a[4]);
    res.push_back(a[9]);
    res.push_back(a[8]);

    return res;

}

vector<int> leftShiftKey_2(vector<int>& a) {

    vector<int> res;
    res.push_back(a[2]);
    res.push_back(a[3]);
    res.push_back(a[4]);
    res.push_back(a[0]);
    res.push_back(a[1]);
    res.push_back(a[7]);
    res.push_back(a[8]);
    res.push_back(a[9]);
    res.push_back(a[5]);
    res.push_back(a[6]);

    return res;

}

vector<int> InitialPermute(vector<int>& a) {

    vector<int> res;
    res.push_back(a[1]);
    res.push_back(a[5]);
    res.push_back(a[2]);
    res.push_back(a[0]);
    res.push_back(a[3]);
    res.push_back(a[7]);
    res.push_back(a[4]);
    res.push_back(a[6]);

    return res;

}

vector<int> InverseIPFunction(vector<int>& a) {

    vector<int> res;
    res.push_back(a[3]);
    res.push_back(a[0]);
    res.push_back(a[2]);
    res.push_back(a[4]);
    res.push_back(a[6]);
    res.push_back(a[1]);
    res.push_back(a[7]);
    res.push_back(a[5]);

    return res;

}

int binaryConversion(int one, int two)
{

	if (one && two)
		return 3;
	else if (one && !two)
		return 2;
	else if (!one && two)
		return 1;
	else
		return 0;

}

void decimalConversion(int decimal, vector<int> ph4[])
{
	bool bits[2]{};

	if (decimal == 3)
	{
		bits[0] = 1;
		bits[1] = 1;
	} else if (decimal == 2)
	{
		bits[0] = 1;
		bits[1] = 0;
	}
	else if (decimal == 1)
	{
		bits[0] = 0;
		bits[1] = 1;
	}
	else
	{
		bits[0] = 0;
		bits[1] = 0;
	}
		
	ph4[0] = bits[0];
	ph4[1] = bits[1];

}

vector<int> FunctionFK(vector<int> text, vector<int> subkey1) {
    
    vector<int> res;

    // E/P Expansion permutation
    vector<int> eP;         // values for the text being permuted
    int p4Decimal[2];       // decimal values returned from the tables
    vector<int> tR[4];      // tavke result container (from positions in s0 and s1)

    eP.push_back(text[7]^subkey1[0]);
    eP.push_back(text[4]^subkey1[1]);
    eP.push_back(text[5]^subkey1[2]);
    eP.push_back(text[6]^subkey1[3]);
    eP.push_back(text[5]^subkey1[4]);
    eP.push_back(text[6]^subkey1[5]);
    eP.push_back(text[7]^subkey1[6]);
    eP.push_back(text[4]^subkey1[7]);

    // get values from tables
    p4Decimal[0] = S0[binaryConversion(eP[0], eP[3])][binaryConversion(eP[1], eP[2])];
    p4Decimal[1] = S1[binaryConversion(eP[4], eP[7])][binaryConversion(eP[5], eP[6])];

    const auto first = p4Decimal[0];
	const auto second = p4Decimal[1];

    // vector<int> p4Holder1;
    // p4Holder1.push_back(0);
    // p4Holder1.push_back(0);
	// decimalConversion(first, p4Holder1);
	// vector<int> p4Holder2[2] = { 0,0 };
	// decimalConversion(second, p4Holder2);

    // tR[0] = p4Holder1[1] ^ text[0];
	// tR[1] = p4Holder2[1] ^ text[1];
	// tR[2] = p4Holder2[0] ^ text[2];
	// tR[3] = p4Holder1[0] ^ text[3];


}




