package IPv4Address;

public class IPv4Address {
    private long lIPAddress;
    private String sIPAddress;

    private void validStringIP(String address) {
        if ( address == null || address.isEmpty() ) {
            throw new IllegalArgumentException("Address is empty!");
        }

        String temp[] = address.split("\\.");
        if ( temp.length != 4 ) {
            throw new IllegalArgumentException("Not enough octets!");
        }

        for ( String str : temp ) {
            int n = Integer.parseInt(str);

            if ( n < 0 || n > 255 ) {
                throw new IllegalArgumentException("Invalid value in octet!");
            }
        }
    }

    public IPv4Address(String address) throws IllegalArgumentException {
        this.validStringIP(address);

        String[] octets = address.split("\\.");

        for ( String octet : octets ) {
            this.lIPAddress = Integer.parseInt(octet) + (this.lIPAddress << 8);
        }
        this.sIPAddress = address;
    }

    public IPv4Address(long address) throws IllegalArgumentException {
        if ( address < 0 || address > 4294967295L ) { // 0.0.0.0 - 255.255.255.255
            throw new IllegalArgumentException("Address is too short / too long!");
        }

        this.lIPAddress = address;

        String octets[] = new String[4];

        for ( int i = 3; i >= 0; i-- ) {
            octets[i] = String.valueOf(address & 255);
            address >>= 8;
        }

        this.sIPAddress = String.join(".", octets);
    }

    public boolean lessThan(IPv4Address address) {
        return this.lIPAddress < address.lIPAddress;
    }

    public boolean greaterThan(IPv4Address address) {
        return !this.lessThan(address);
    }

    public boolean equals(IPv4Address address) {
        return this.lIPAddress == address.lIPAddress;
    }

    public String toString() {
        return this.sIPAddress;
    }

    public long toLong() {
        return this.lIPAddress;
    }

//    public void smth() throws IOException {
////        try (DataOutputStream dos = new DataOutputStream(new FileOutputStream("output.txt"));
////                DataInputStream dis = new DataInputStream(new FileInputStream("output.txt"))) {
////
////            dos.writeUTF("Zhopa");
////            dos.writeInt(10);
////            dos.writeBoolean(true);
////            dos.writeDouble(1.56);
////
////            System.out.printf("Name: %s, Age: %d, Man: %b, Height: %f", dis.readUTF(), dis.readInt(), dis.readBoolean(),
////                                                                        dis.readDouble());
////
////        } catch (FileNotFoundException e) {
////            e.printStackTrace();
////        }
//        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//                BufferedWriter bw = new BufferedWriter(new FileWriter("output.txt"))) {
//
//
//            String txt;
//
//            while ( !(txt = br.readLine()).equals("ESC") ) {
//                bw.write(txt + "\n");
//                bw.flush();
//            }
//        }
//
//    }

        public static void main(String[] args) {
        IPv4Address ip = new IPv4Address("192.168.1.1");
//        ip.smth();
    }
}
