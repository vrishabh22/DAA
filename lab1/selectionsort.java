import java.io.*;
import java.util.*;
import java.lang.*;
public class selectionsort{
        public static void selectionSort(int[] arr){
            for (int i = 0; i < arr.length - 1; i++)
            {
                int min = i;
                for (int j = i + 1; j < arr.length; j++){
                    if (arr[j] < arr[min]){
                        min = j;
                    }
                }
                int t = arr[min];
                arr[min] = arr[i];
                arr[i] = t;
            }
        }
        public static void main(String args[]){
            int[] arr1 = {9,14,3,2,43,11,58,22};
            selectionSort(arr1);
            for(int i:arr1){
                System.out.print(i+" ");
            }
        }
    }
