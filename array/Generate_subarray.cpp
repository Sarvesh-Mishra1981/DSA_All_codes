// void generate_subset(vector<int>& m,int n,vector<int>& b, vector<vector<int>>& a){
//         if(n==0){
//             a.push_back(b);
//             return;
//         }
//         b.push_back(m[n-1]);
//         generate_subset(m,n-1,b,a);
//         b.pop_back(); 
//         generate_subset(m,n-1,b,a);
//     }