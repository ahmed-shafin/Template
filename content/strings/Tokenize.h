/**
 * Author: Johan Sannemo
 * Date: 2016-12-15
 * License: CC0
 * Description: Tokenizer wrt delimiter
 * Time: O(n)
 * Status: Tested on kattis:stringmatching
 */
string trim(const string& str) {
  size_t first = str.find_first_not_of(" \t\n\r");
  size_t last = str.find_last_not_of(" \t\n\r");
  if (first == string::npos || last == string::npos)
    return "";
  return str.substr(first, (last - first + 1));
}
bool isDelimiter(char ch, const set<char>& delimiters) {
  return delimiters.find(ch) != delimiters.end();
}
vector<string> tokenize(const string& input, const string& delimiters) {
  set<char> delimiterSet(delimiters.begin(), delimiters.end());
  vector<string> tokens;
  string token;

  for (char ch : input) {
    if (isDelimiter(ch, delimiterSet)) {
      if (!token.empty()) {
        tokens.push_back(token);
        token.clear();
      }
      tokens.push_back(string(1, ch));
    } else {
      token += ch;
    }
  }
  if (!token.empty()) tokens.push_back(token);
  
  return tokens;
}
