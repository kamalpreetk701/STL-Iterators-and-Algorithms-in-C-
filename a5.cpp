#include"iostream"
#include<string>
#include<algorithm>
#include<iterator>
#include<vector>
#include"fstream"
#include<map>
#include<sstream>
#include<iomanip>
#include<set>
using namespace std;




bool is_Palindrome(const std::string &phrase)
{
	string temp;
	auto lambda = [](char x) {return !isalpha(x); };

	remove_copy_if(phrase.begin(), phrase.end(), back_inserter(temp),lambda) ;

	transform(temp.begin(), temp.end(), temp.begin(), [](char x) {return tolower(x);});
	
	int mid = temp.length()/2;
	bool result=equal(temp.begin(), temp.begin() + mid, temp.rbegin(), [](char x, char y) {return  (x == y); });
	
	return result;
}


void test_is_palindrome()
{
	string str_i = string("was it a car or a cat i saw?");
	string str_u = string("was it a car or a cat u saw?");
	cout << "the phrase \"" << str_i << "\" is" << (is_Palindrome(str_i) ? " " : " not ") << "a palindrome \n";
	cout << "the phrase \"" << str_u << "\" is" << (is_Palindrome(str_u) ? " " : " not ") << "a palindrome\n";
}


template<class Iterator>
std::pair<Iterator, bool> second_max(Iterator start, Iterator finish)
{
	pair<Iterator, bool> result;
	int count = 0;
	int len = finish - start;

	Iterator secmax = start;
	Iterator max=start;
	
	if (start == finish)
	{
		result.first = finish;
		result.second = false;
	}
	else
	{
		while (start != finish)
		{
			if (*start > *max)
			{
				secmax = max;
				max = start;
			}
			else if (*start<*max && *start > *secmax)
			{
				secmax = start;
				
			}
			else if (*start == *max)
			{
				count++;
			}
			else if(*start<*max&& *max==*secmax)
			{
				secmax = start;
			}
			start++;
		}
		
	}
	if(len==count)
	{
		result.first = max;
		result.second = false;
	}
	else
	{
		result.first = secmax;
		result.second = true;
	}
	return result;
}



void test_second_max()
{
	vector<int> int_vec{1,1,5,5,7,7};

	auto retval = second_max(int_vec.begin(), int_vec.end());
	
	if (retval.second)
		cout << "second largest elemnt is: " << *retval.first<<endl;
	else
	{
		if (retval.first == int_vec.end())
			cout << "List Empty,no Elements"<<endl;
		else
			cout << "Containers element are all equal"<<endl;
	}
}



class MyCompare : public std::binary_function<string, string, bool>
{
public:
	bool operator()(const string & lhs, const string & rhs) const
	{
		string temp1 = lhs;
		string temp2 = rhs;
		transform(lhs.begin(), lhs.end(), temp1.begin(), tolower);
		transform(rhs.begin(), rhs.end(), temp2.begin(), tolower);
		return temp1 < temp2;
	}
};



string remove_leading_trailing_nonalpha(string & word)
{
	
	
	if (!isalpha(*(--word.end())))
	{	
		word.pop_back();
	}

	if (!isalpha(word[0]))
	{
		word.erase(word[0]);
	}
	return word;
}



void print_word_frequency1(const std::string &filename) 
{

	ifstream ifs;
	ifs.open(filename);

	if (!ifs.is_open())
		throw invalid_argument(string("could not open file") + filename);

	map<string, int>word_frequency_map;
	
	string line;

	while (getline(ifs, line))
	{
		std::istringstream iss(line);
		string word;
		while (iss >> word)
		{
			++word_frequency_map[remove_leading_trailing_nonalpha(word)];
		}
	}
		

	for (const auto &word : word_frequency_map)
	{
		cout << setw(10) << word.first << " " << word.second << endl;
	}
}




void print_word_frequency2(const std::string &filename)
{
	ifstream ifs;
	ifs.open(filename);

	if (!ifs.is_open())
		throw invalid_argument(string("could not open file") + filename);

	map<string, int,MyCompare>word_frequency_map;

	string line;

	while (getline(ifs, line))
	{
		std::istringstream iss(line);
		string word;
		while (iss >> word)
		{
			++word_frequency_map[remove_leading_trailing_nonalpha(word)];
		}
	}


	for (const auto &word : word_frequency_map)
	{
		cout << setw(10) << word.first << " " << word.second << endl;
	}
}


void print_word_index(const std::string &filename)
{
	ifstream ifs;
	ifs.open(filename);

	if (!ifs.is_open())
		throw invalid_argument(string("could not open file") + filename);
	int count = 0;
	map<string,set<int>, MyCompare>word_frequency_map;
	string word;
	string line;
	set<int> set1;
	while (getline(ifs, line))
	{
		count++;
		std::istringstream iss(line);
		
		while (iss >> word)
		{	
			word_frequency_map[remove_leading_trailing_nonalpha(word)].insert(count);
		}
	}

	for (const auto & word : word_frequency_map)
	{
		cout << setw(10) << word.first;
		set<int> temp = word.second;
		set<int>::iterator iter;
		for (iter = temp.begin(); iter != temp.end(); ++iter)
		{
			cout <<" "<< *iter;
		}
		cout << endl;
	}
}


void main()
{
	
	test_is_palindrome();
	cout << "--------------------------------------------------------"<<endl;
	test_second_max();
	cout << "--------------------------------------------------------"<<endl;

	string filename = "C:/Users/kamal/Desktop/input1.txt";

	print_word_frequency1(filename);
	cout << "---------------------------------------------------------"<<endl;

	print_word_frequency2(filename);
	cout << "----------------------------------------------------------"<<endl;
	
	print_word_index(filename);

	cin.get();
}