import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class HappyNum {

    public static void main(String [] args){

        System.out.print("Introduce a number: ");
        int num = new Scanner(System.in).nextInt();
        Set<Integer> repeatedNum = new HashSet<>(); //hash set to deny repeated nums
        int countNum = 0; //number of new numbers created
        boolean happy = true; //is happy or not

        while(num != 1){ //if leaves the cycle naturally then its an happy number
            int total = 0, rest;
            while(num != 0){
                rest = num % 10; //decimal part
                num /= 10; //whole part
                total += rest * rest;
            }
            countNum++; //+1 new number created
            num = total; //num takes the new number created
            repeatedNum.add(num); //add the new number to the array
            if(countNum != repeatedNum.size()){ //verifies if the new number already exists in the array
                //if yes, then we have a cycle and the the number is not happy
                happy = false;
                break; //if leaves the cycle because of a break then its not an happy number
            }
        }

        if(happy){ //if is an happy number
            System.out.println("It's an happy number");
        }else{ //if not
            System.out.println("It's not an happy number");
        }

    }
}
