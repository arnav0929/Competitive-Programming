/*Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). 
n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). 
Find two lines, which, together with the x-axis forms a container, such that the container contain the most water.*/
int maxArea(vector<int>& hei) {
    int n=hei.size(),i=0,j=n-1,area=0;
    while(i<j){
        if(hei[i]<hei[j]){
            area=max(area,hei[i]*(j-i));   
            i++;
        } 
        else{
            area=max(area,hei[j]*(j-i));
            j--;
        }
    }
    return area;
}
