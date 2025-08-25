// Demonstrate nested try blocks.
class NestedTry {
    public static void main(String args[]) {
        try {
            int a = args.length;
            System.out.println("a = " + a);
            int b = 42 / a;  
            try {
                if (a == 1) {
                    int c = a / (a - a);  
                }
                if (a == 2) {
                    int[] d = {1, 5, 6};
                    d[42] = 99; 
                }
            } catch (ArrayIndexOutOfBoundsException e) {
                System.out.println("Array index out-of-bounds: " + e);
            }

        } catch (ArithmeticException e) {
            System.out.println("Division by zero: " + e);
        }
    }
}
