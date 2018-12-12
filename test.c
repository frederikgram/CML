#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Tools

float distance(float a, float b){
	return a - b;
};

void swap(float *xp, float *yp) 
{ 
    float temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
}; 
  
// A function to implement bubble sort 
void bubbleSort(float point, float *arr, int n) { 
   int i, j; 
   for (i = 0; i < n-1; i++){      
  
       // Last i elements are already in place    
       for (j = 0; j < n-i-1; j++){  
           if (distance(point, arr[j]) > distance(point, arr[j+1])){ 
              swap(&arr[j], &arr[j+1]); 
          	}
        }
    }
};


// Initialize base dataset
float *data;
int *labels;
int dataset_len = 0;

int count_uniques(float arr[]){
	int k = 0; 

	int *unique_labels = malloc(dataset_len); 

	for(int i; i < dataset_len; i++){
		int match = 0; 

		for(int j; j < k; j++){
			if(labels[i] == unique_labels[j]){
				match = 1;
				break;
			}
		}

		if(match == 0){
			int *tmp_unique_labels = malloc(k + 1);
			memcpy(tmp_unique_labels, unique_labels, k);
			free(unique_labels);
			unique_labels = tmp_unique_labels;
			unique_labels[k] = labels[i];
			k++;
		}	
	}
	free(unique_labels);
	k++;
	return k;
};

void fit(float *_data, int *_labels, int _len){
	// Sets global dataset
	data = malloc(_len);
	labels = malloc(_len);

	data = _data;
	labels = _labels;
	dataset_len = _len;
}


int predict(float X, int k){

	// automatically find fitting k value
	// if k hasnt been specified
	if(k == 0){
		k = count_uniques(data);
		printf("k was set to %d automatically\n", k);
	};

	// Sort dataset by euclidian distance to X
	bubbleSort(X, data, dataset_len);
	printf("%d", data[0]);

};

void main(){
	printf("knn ML\n");

	float points[5] = {1.0, 2.0, 10.0, 11.0, 20.0};
	int labels[5] = {1, 1, 2, 2, 3};

	fit(points, labels, 5);

	predict(1.5, 0);
}