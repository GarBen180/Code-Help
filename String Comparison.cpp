/***********************************************************************
* Program:
*    Assignment 01, Genetic Genealogy
*    Brother Comeau, CS165
* Author:
*    Garrett Bennett
* Summary:
*    This program uses a single genetic marker to allow a user to
*    search for relatives. This is done by gathering various strands of
*    DNA each at 10 characters each, and comparing them to the strand
*    of the user to see if there is a match or not.
*
*    Estimated:  1.0 hrs
*    Actual:     2..75 hrs
*      Most difficult part: The comparison of the individual characters
*      of the user's DNA and the relatives DNA. At first it was an issue
*      of not knowing how strings worked, then it became an issue of
*      how to set up a function to tackle the comparison, and along with
*      all of that hullabaloo there was the task of learning the syntax
*      that goes along with strings and comparisons.
************************************************************************/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

/**********************************************************************
* getUserDNA: get the user's DNA sequence
***********************************************************************/
string getUserDNA()
{
	string userDNA;

	cout << "Enter your DNA sequence: ";
	cin >> userDNA;

	return userDNA;
}

/**********************************************************************
*getNumRelatives: get how many potential relatives there are
***********************************************************************/
int getNumRelatives()
{
	int numRel;

	cout << "Enter the number of potential relatives: ";
	cin >> numRel;

	return numRel;
}

/**********************************************************************
* getRelNames: get the names of the potential relatives
***********************************************************************/
string getRelNames(int sizea)
{
	string relNames;

	for (int i = 0; i < sizea; i++)
	{
		cout << "Please enter the name of relative #" << i + 1 << ": ";
		cin >> relNames[i]; // this part is broken
	}

	return relNames;
}

/**********************************************************************
* getRelDNA: get the DNA sequences of the potential relatives
***********************************************************************/
string getRelDNA(int sizeb, string names[50])
{
	string relDNA;

	for (int i = 0; i < sizeb; i++)
	{
		cout << "Please enter the DNA sequence for " << names[i] << ": ";
		cin >> relDNA[i]; //because rel names is broken this one should be too
	}

	return relDNA;
}

/**********************************************************************
* displayPercentRel: compute the percent relation of user and
* potential relative DNA
***********************************************************************/
int compareDNA(string dnaUser, string dnaRels)
{
	int count = 0;

	for (int i = 0; i < 10; i++)
	{
		if (dnaUser[i] == dnaRels[i])
			count++;
	}

	return count;
}

/**********************************************************************
* displayPercentRel: compute the percent relation of user and
* potential relative DNA
***********************************************************************/
void displayPercentRel(int sizec, string namesRel[50], string userDNAb, string relDNAb[50])
{
	for (int i = 0; i < sizec; i++)
	{
		cout << "Percent match for " << namesRel[i] << ": ";

		for (int row = 0; row < sizec; row++)
		{
			int count = compareDNA(userDNAb, relDNAb[row]);
			cout << count * 10.0;
		}
	}

}

/**********************************************************************
* main: call all the functions
***********************************************************************/
int main()
{
	// get user dna
	string userDNA = getUserDNA();

	// get number of potential relatives
	int num = getNumRelatives();

	// get the names of the potential relatives
	string names[50] = { getRelNames(num) };

	// get dna for each potential relative
	string relDNA[50] = { getRelDNA(num, names) };

	// display the percent relation to user for each potential relative
	displayPercentRel(num, names, userDNA, relDNA);

	return 0;
}

