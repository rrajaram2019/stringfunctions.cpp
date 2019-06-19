// Copyright 2018 Soumya Nag Suman soumya@bu.edu
// Copyright 2018 Rahul Rajaram rrajaram@bu.edu
// error  output  is coded as follows:
// w - is_word
// p - is_palindrome
// a - add
// c - convertbase
// m - multibase
#include <iostream>
#include <string>
using std::string;
using std::cerr;
using std::cout;
using std::cin;
using std::stoi;


bool iscapital(char x) {
  if (x >= 'A' && x <= 'Z')
    return 1;
  else
    return 0;
}
bool is_word(string s) {
  bool isFirst = false;
  int low = 0, upper = 0;
  if (s.size() == 0)
    return false;
  for (int i = 0 ; i < s.size(); ++i) {
    if (islower(s[i])) {
      ++low;
    } else if (isupper(s[i])) {
      ++upper;
    } else {
      return false;
    }
  }
  if (s.size() > 0 && iscapital(s[0]))
    isFirst = true;
  if (isFirst && upper == s.size()) {
    return true;
  } else if (isFirst && low == s.size() - 1) {
    return true;
  } else if (upper == s.size()) {
    return true;
  } else if (low == s.size()) {
    return true;
  }
  return false;
}
bool is_valid(string num) {
  if (num.length() == 1 && num[0] == '0')
    return false;
  if (num[0] == '0')
    return true;
  for (int i = 0; i < num.length(); i++) {
    if (!(num[i] >= '0' && num[i] <= '9'))
      return true;
  }
  return false;
}
bool is_palindrome(string num, bool *error) {
  int len = num.length();
  int i = 0;
  int index = 0;
  int match = 0;
  for (i; i < len; i++) {
    if (isdigit(num[i])) {
      index++;
    }
  }
  if (len == index) {
    if (index >> 1 && num[0] == '0') {
      *error = true;
      return false;
    } else if (index == 1) {
      *error = false;
      return true;
    } else if (index >> 1) {
      i = 0;
      for (i; i < index; i++) {
        if (num[i] == num[index - i - 1]) {
          match++;
        }
      }
      if (match == index) {
        *error = false;
        return true;
      } else {
        *error = false;
        return false;
      }
    }
  } else {
    *error = true;
    return false;
  }
  return false;
}
string add(const string &num1, const string &num2) {
  string result = "";
  int carry = 0, sum, digit1, digit2;
  char chr;
  int index1 = num1.length() - 1;
  int index2 = num2.length() - 1;
  while (index1 >= 0 || index2 >= 0) {
    digit1 = 0;
    digit2 = 0;
    if (index1 >= 0) {
      digit1 = num1[index1] - '0';
    }
    if (index2 >= 0) {
      digit2 = num2[index2] - '0';
    }
    sum = digit1 + digit2 + carry;
    carry = 0;
    if (sum > 9) {
      carry = sum / 10;
      sum = sum % 10;
    }
    chr = '0' + sum;
    result = chr + result;
    index1--;
    index2--;
  }
  if (carry > 0) {
    chr = '0' + carry;
    result = chr + result;
  }
  return result;
}
string convertbase(const string& numstr, const int frombase, const int tobase) {
  int length_numstr = numstr.size();
  int power = 1;
  int sum = 0;
  int nextnum = 0;
  int remainder = 0;
  int i = 0;
  string newbase = "";
  for (i = length_numstr - 1; i >= 0; i--) {
    sum += (numstr[i] - '0') * power;
    power *= frombase;
  }
  while (sum != 0) {
    nextnum = sum / tobase;
    remainder = sum % tobase;
    if (remainder == 10) {
      string sremainder = ":";
      newbase = sremainder + newbase;
    } else if (remainder == 11) {
      string sremainder = ";";
      newbase = sremainder + newbase;
    } else if (remainder == 12) {
      string sremainder = "<";
      newbase = sremainder + newbase;
    } else if (remainder == 13) {
      string sremainder = "=";
      newbase = sremainder + newbase;
    } else if (remainder == 14) {
      string sremainder = ">";
      newbase = sremainder + newbase;
    } else if (remainder == 15) {
      string sremainder = "?";
      newbase = sremainder + newbase;
    } else {
      newbase = std::to_string(remainder) + newbase;
    }
    sum = nextnum;
  }
  return newbase;  // fix this line
}
bool my_is_palindrome(string num) {
  int len = num.length();
  char index;
  for (int i = 0; i <= len / 2; i++) {
    index = num.at(i);
    if (index != num.at(len - i - 1)) {
      return false;
    }
  }
  return true;
}
string multibase(int x) {
  int num;
  int remainder;
  string strnum = "";
  string nextnum = "";
  string palinbase = "";
  for (int i = 2; i < x; i++) {
    num = x;
    nextnum = "";
    while (num != 0) {
      remainder = num % i;
      num = num / i;
      strnum = remainder + '0';
      nextnum = strnum + nextnum;
    }
    if (my_is_palindrome(nextnum)) {
      palinbase += " " + std::to_string(i);
    }
  }
  palinbase = palinbase.substr(1);
  return palinbase;
}
// leave this line and everything below as is
int main() {
  bool error;

  cerr << std::boolalpha;
  cout << std::boolalpha;

  // is_word basic tests
  if (not is_word("test")) cerr << "we1\n";
  if (not is_word("Test")) cerr << "we2\n";
  if (not is_word("TEST")) cerr << "we3\n";
  if (not is_word("thisisaword")) cerr << "we4\n";

  if (is_word("123")) cerr << "we5\n";
  if (is_word("")) cerr << "we6\n";
  if (is_word("abc123abc")) cerr << "we7\n";
  if (is_word("tEst")) cerr << "we8\n";
  if (is_word("tEst")) cerr << "we9\n";
  if (is_word("TESTer")) cerr << "we10\n";


  // is_palindrome basic tests
  if (not is_palindrome("12321", &error) or error) cerr << "pe1\n";
  if (not is_palindrome("9009", &error) or error) cerr  << "pe2\n";
  if (not is_palindrome("9", &error) or error)  cerr << "pe3\n";
  if (not is_palindrome("123456777654321", &error) or error) cerr << "pe4\n";

  if (is_palindrome("abcba", &error) or not error) cerr << "pe5\n";
  if (is_palindrome("12321 a", &error) or not error) cerr << "pe6\n";
  if (is_palindrome("0012100", &error) or not error) cerr << "pe7\n";

  if (is_palindrome("123", &error) or error) cerr << "pe8\n";
  if (is_palindrome("123211", &error) or error) cerr << "pe9\n";
  if (not is_palindrome("0", &error) or error)  cerr << "pe10\n";

  // add basic tests
  if (add("123", "456") != "579") cerr << "ae1\n";
  if (add("123", "4") != "127") cerr << "ae2\n";
  if (add("1234", "9") != "1243") cerr << "ae3\n";
  if (add("88", "12") != "100") cerr << "ae4\n";
  if (add("1234567890123456789", "10000000000000999")
      != "1244567890123457788") cerr << "ae5\n";

  string longone(120, '2');
  longone[0] = '3';
  string longother(123, '1');
  longother[0] = '4';
  longother[3] = '2';
  string longresult(123, '3');
  longresult[0] = '4';
  longresult[1] = '1';
  longresult[2] = '1';
  longresult[3] = '5';

  if (add(longone, longother) != longresult ) cerr << "ae6\n";

  // convertbase tests

  if (convertbase("1111", 2, 10) != "15" ) cerr << "ce1\n";
  if (convertbase("255", 10, 16) != "??")  cerr << "ce2\n";
  if (convertbase("755", 8, 2) != "111101101") cerr << "ce3\n";

  if (convertbase("987123", 30, 30) != "987123" ) cerr << "ce4\n";
  if (convertbase("azbc", 100, 10) != "49745051") cerr << "ce5\n";

  if (convertbase("azbc", 100, 2) != "10111101110000110010011011")
    cerr << "ce6\n";

  // multibase tests

  if (multibase(121) != "3 7 8 10 120") cerr << "me1\n";
  if (multibase(45) != "2 8 14 44") cerr << "me2\n";
  if (multibase(63) != "2 4 8 20 62") cerr << "me3\n";
  if (multibase(10) != "3 4 9") cerr << "me4\n";


  // ad-hoc tests from cin

  string asktype;
  bool res;
  string userinput, num1, num2;
  int mbase, frombase, tobase;



  while (cin >> asktype) {
    if (asktype == "w") {  // is_word
      std::cin >> userinput;
      cout << is_word(userinput) << "\n";
    } else if (asktype == "p") {  // p - is_palindrome
      std::cin >> userinput;
      res = is_palindrome(userinput, &error);
      cout << res << " " << error << "\n";
    } else if (asktype == "a") {  // a - add
      std::cin >> num1 >> num2;
      cout << add(num1, num2) << "\n";
    } else if (asktype == "c") {  // c - convertbase
      std::cin >> userinput >> frombase >> tobase;
      cout << convertbase(userinput, frombase, tobase) << "\n";
    } else if (asktype == "m") {  // m - multibase
      std::cin >> mbase;
      cout << multibase(mbase) << "\n";
    } else {
      return 0;
    }
  }
  return 0;
}
