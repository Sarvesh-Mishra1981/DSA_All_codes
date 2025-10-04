/*
so the basic idea of the articulte point is that it is the point if we will remove that then the graph wull be divided into 
2 or mor ethan the 2 parts and hence this is called the articulte points and so what is the basic


naive approch--
we will traverse the each point and see that wether it is articulate point or not that is just by going to each and every point and then what
we will do is that we will remove that point and vount the number of the distinct points in it 
thorugh the idea of the disconned dfs 
time complexity-O((v+e)^2)

better approach--
think that ek point articulte kab bananta hai only when it has only one path way that it can be ascessed from only one path
hence if we will remove the just before element of the node then the it wil be articulte point
to do this what we will do is that we will make 4 index-----
1. distance -in this we will make the first diatnce when we reached that node
2. low-- in this we will update the time when we reached basicilly the low time that we can ascess that node
3, visited -- it will show thgat wether that node is visited or not
4. parent --- give the info regarding the parent of the node
..... so what the basic idea is that we will use the Tarjan algorith and inthat algo what we learn that 

if-- low[child]> low[parent] then it is articulte point and this means that child can be ascessed later than the parent 
so it is only the path for reaching that node so if we will remove that parent then it will seperate

and such point is called the bridge in the graph..
Implementation in the next part
*/