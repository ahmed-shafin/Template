/**
 * Author: Johan Sannemo
 * Date: 2016-12-15
 * License: CC0
 * Description: A string is called simple (or a Lyndon word), if it is strictly smaller than any of its own nontrivial suffixes
 * The Lyndon factorization of the string s is a factorization S = wi  where wi are simple, and in non-increasing order
 * Time: O(n)
 * Status: Tested on kattis:stringmatching
 */

 vector<string> duval(string const& s) {
    int n = s.size();
    int i = 0;
    vector<string> factorization;
    while (i < n) {
        int j = i + 1, k = i;
        while (j < n && s[k] <= s[j]) {
            if (s[k] < s[j])
                k = i;
            else
                k++;
            j++;
        }
        while (i <= k) {
            factorization.push_back(s.substr(i, j - k));
            i += j - k;
        }
    }
    return factorization;
}
