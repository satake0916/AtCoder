class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        int ans = 0;
        Set<Character> st = new HashSet<>();
        int start = 0, end = 0;
        while(start < n && end < n){
            if(!st.contains(s.charAt(end))){
                st.add(s.charAt(end++));
                ans = Math.max(ans, end - start);
            }else{
                st.remove(s.charAt(start++));
            }
        }
        return ans;
    }
}
