/*

编写一个函数，以字符串作为输入，反转该字符串中的元音字母。

示例 1:

输入: "hello"
输出: "holle"
示例 2:

输入: "leetcode"
输出: "leotcede"
说明:
元音字母不包含字母"y"。

*/

class Solution {
    public String reverseVowels(String s) {
        if(s == null || s.length() == 0)
            return s;
        String vowels = "aeiouAEIOU";
        char[] arr = s.toCharArray(); 
        int i = 0, j = s.length() - 1;
        while(i < j){
            while(i < j && vowels.indexOf(arr[i]) == -1)
                i++;
            while(i < j && vowels.indexOf(arr[j]) == -1)
                j--;
            if(i < j) {
                char temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
                j--;
            }
        }
        return new String(arr);
    }
}
