/*
 * @description 二分法找有序数组的元素
 * @return key -1表示未找到
 */

import java.util.Scanner;
public class BinSearch {
    public static void main(String[] args) {

        int[] arr={0,1,2,3,4,5,6,7,8,9,10};
        String str=" ";
        for (int i = 0; i < arr.length; i++){
            if(i==0) str = Integer.toString(arr[i]);
            else str += "," + Integer.toString(arr[i]);
        }
        System.out.println("Arr: {" + str + "}  Num: " + arr.length);

        /*if (args.length <= 0) {
            args=new String[]{"2"};
        }
        int key = Integer.parseInt(args[0]);*/

        Scanner sc = new Scanner(System.in); 
        System.out.print("Please input the key which you want to serach："); 
        int key = sc.nextInt();
        sc.close();
        System.out.println("Key: " + key);

        int start = 0;
        int end = arr.length - 1;
        int mid;
        int index = -1;
        while (start <= end){
            mid = (start + end)/2;
            if(key == arr[mid]){
                index = mid;
                break;
            }else if ( key < arr[mid]){
                end = mid - 1;
            } else{
                start = mid + 1;
            }
        }
        System.out.println("Index: " + index);
    }
}