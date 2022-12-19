import java.util.*;

public class code {

		static int x;

		public static void kv() {
			x = x * x;
		}

    public static void main(String [] args) {
    	Scanner in = new Scanner(System.in);

    	x = in.nextInt();
    	// x * x
    	System.out.println(x);

    }
}