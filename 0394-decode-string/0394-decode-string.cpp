class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
  stack<string>st;
  stack<int>digit;

  string curr = "";
  for(int i=0;i<n;i++){
    if(isdigit(s[i])){
      int num = 0;
      while(i<s.size() && isdigit(s[i])){
        num = num*10 +(s[i]-'0');
        i++;
      }
      i--;
      digit.push(num);
    }else if(s[i] == '['){
      st.push(curr);
      curr = "";
    }else if(s[i]==']'){
      string temp = "";
      string prev = st.top(); st.pop();
      int dig = digit.top(); digit.pop();

      for(int count=0;count<dig;count++){
        temp += curr;
      }
      curr = prev+temp;
    }else{
      curr += s[i];
    }
  }
  return curr;
    }
};