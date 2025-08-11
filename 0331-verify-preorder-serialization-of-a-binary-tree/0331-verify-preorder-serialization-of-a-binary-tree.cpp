class Solution {
public:
    bool isValidSerialization(string preorder) {
        int slot = 1;
        int n = preorder.size();
        int i=0;

        while(i<n){
            if(slot-1 < 0) return false;
            else slot--;

            if(preorder[i]!='#'){
                while(i<n && preorder[i]!=',') i++;

                slot+=2;
            }else{
                i++;
            }

            if(i<n && preorder[i]==',') i++;
        }
        if(slot == 0) return true;
        return false;
    }  
};