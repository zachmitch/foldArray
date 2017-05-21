#include <vector>
#include <iostream>
#include <string>


class Fold 
{
	//Parameters:
	//array:  original vector full of ints
	//runs:  Number of times to fold array


	public:
    	std::vector<int> foldArray(const std::vector<int> array, int runs)
    	{
  
		//Copy of original array
 		std::vector<int> normalArray;
      		
		//Array after it is folded
		std::vector<int> bentArray;
      		
		//Midpoint of the array
		int midPoint;
      		
		//Whether the array has an even/odd number of members
		bool isEven;
     
		//Copy each member of original array 
      		for(int i = 0; i < array.size(); i++) 
        	{
			normalArray.push_back(array[i]);
      		}

		//For each fold
		//Find the midpoint and whether array has odd/even members
		//Clear the bent array if there are members in it
		//Add members to bent array starting w/ 0 + n - 0, 1 + n -1, 2 + n-2, etc.
		//If odd number of members, add last member of original array 
		//Clear normal arry
		//Overwrite normal array with bent array, for another iteration if needed
      		while(runs > 0)
      		{
      			//Find midpoint and if even/odd 
        		midPoint = normalArray.size()/2;  
        		isEven = normalArray.size() % 2 == 0;

			//Clear bent array
	 		if(!bentArray.empty())
          		{
				bentArray.clear();
			}	
			
			//Add members to bent array
        		for(int i = 0; i < midPoint; i++) 
        		{
	  			bentArray.push_back(normalArray[i] + normalArray[(normalArray.size()-1)-i]);
        		}

			//Add last member if odd sized array
        		if(!isEven) 
          		{
				bentArray.push_back(normalArray[midPoint]);
          		}

			//Clear normal array
        		normalArray.clear(); 
        
			//Overwrite normal array
        		for(int i = 0; i < bentArray.size(); i++) 
          		{
				normalArray.push_back(bentArray[i]);
          		}
        
        		runs--;
      		}
     
		//Output for user so they know it's been folded 
 		std::cout << "\nBent array after folding: " << std::endl;
		
		for (int i = 0; i < bentArray.size(); i++)
		{
			std::cout << bentArray[i] << " ";  
		}
		std::cout << std::endl;   
    
        	return bentArray;
    	}
};

int main()
{
	//Test suite

	Fold fold;
	std::vector<int> sample;
	std::cout << "Sample Vector: " << std::endl;
	for(int i = 5; i < 16; i++)
	{
		sample.push_back(i);
	}
	for(int i = 0; i < sample.size(); i++)
	{
		std::cout << sample[i] << " ";
	}


	fold.foldArray(sample, 2);
	


}
