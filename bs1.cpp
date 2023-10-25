#include<bits/stdc++.h>
double minimiseMaxDistance(vector<int> &arr, int k){
	// Write your code here.
  
	int n=arr.size();//size of the arr
  
	priority_queue<pair<long double,int>>pq;//priority queue
	//push everything in priority queue
	for(int i=0;i<n-1;i++)
	{
		pq.push({arr[i+1]-arr[i],i}); //we are pushing the initial difference between the gas stations and corresponding index of homany arr , which is (n-1) in size and initially initialized to 0
	}
	
	vector<int>homany(n-1,0);
	for(int i=1;i<=k;i++)
	{
        pair<long double,int>temp=pq.top();   //pop the element with max distance
		    pq.pop();
        homany[temp.second]++;                   //go to the proper index of howmany and increment its content by 1 , as you are putting 1 gas station in between the correspoding index
		    temp.first=(double)(arr[temp.second+1]-arr[temp.second])/(double)(homany[temp.second]+1);//calculate the new distance between the gas station between those two original gas statino after pushing  incrementing the no of gas statino in last step
		    pq.push(temp);//now push the new content in the heap or priority queue
	}
	return pq.top().first;//return the max distance
    
}
