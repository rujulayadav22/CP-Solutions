class Solution {
  public:
  void insertAtBottom(stack <int>&st,int temp){
      if(st.empty() || st.top() <=temp){
      st.push(temp);
      return;
    }
      int val = st.top();
      st.pop();
      insertAtBottom(st, temp);
      st.push (val);
}
    void sortStack(stack<int> &st) {
        if(st.empty())
        return;
        int temp = st.top();
        st.pop();
        sortStack(st);
        insertAtBottom(st, temp);
    }
};
