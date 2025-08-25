enum Apple {
    Jonathan(10), GoldenDel(9), RedDel(12), Winesap(15), Cortland(8);

    private int price;  // field

    // Constructor
    Apple(int p) {
        price = p;
    }

    // Method
    int getPrice() {
        return price;
    }
}

class EnumClassDemo {
    public static void main(String args[]) {
        Apple ap = Apple.RedDel;
        System.out.println("Price of " + ap + " is " + ap.getPrice());
    }
}
