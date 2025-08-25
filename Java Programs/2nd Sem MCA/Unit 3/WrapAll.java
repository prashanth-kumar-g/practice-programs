class WrapAll {
    public static void main(String args[]) {

        // Byte
        Byte bOb = new Byte((byte)10);
        byte b = bOb.byteValue();
        System.out.println("Byte: " + b + " " + bOb);

        // Short
        Short sOb = new Short((short)20);
        short s = sOb.shortValue();
        System.out.println("Short: " + s + " " + sOb);

        // Integer
        Integer iOb = new Integer(100);
        int i = iOb.intValue();
        System.out.println("Integer: " + i + " " + iOb);

        // Long
        Long lOb = new Long(100000L);
        long l = lOb.longValue();
        System.out.println("Long: " + l + " " + lOb);

        // Float
        Float fOb = new Float(10.5f);
        float f = fOb.floatValue();
        System.out.println("Float: " + f + " " + fOb);

        // Double
        Double dOb = new Double(99.99);
        double d = dOb.doubleValue();
        System.out.println("Double: " + d + " " + dOb);

        // Character
        Character cOb = new Character('A');
        char c = cOb.charValue();
        System.out.println("Character: " + c + " " + cOb);

        // Boolean
        Boolean boolOb = new Boolean(true);
        boolean bool = boolOb.booleanValue();
        System.out.println("Boolean: " + bool + " " + boolOb);
    }
}
