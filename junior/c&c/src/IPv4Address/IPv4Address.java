package IPv4Address;

public class IPv4Address {
    private static final long maxIP = 4294967295L;
    private long ipAddress;

    private int[] validStringIP(String address) throws IPAddressException {
        if ( address == null || address.isEmpty() ) {
            throw new IPAddressException("Address is empty!"); // ?
        }

        String[] temp = address.split("\\."); // ?

        if ( temp.length != 4 ) {
            throw new IPAddressException("Not enough octets!"); // ?
        }

        int[] result = new int[4]; // ?
        int counter = 0; // ?
        int octet; // ?

        for ( String str : temp ) {
            String s = str.trim(); // ?

            if ( s.isEmpty() || !s.matches("\\d+") ) {
                throw new IPAddressException("Octet is null OR have smth besides digits");
            }
            octet = Integer.parseInt(s);

            if ( octet < 0 || octet > 255 ) {
                throw new IPAddressException("Invalid value in octet!"); // ?
            }
            result[counter] = octet;
            counter += 1;
        }
        return result;
    }

    public IPv4Address(String address) throws IllegalArgumentException, IPAddressException {
        int[] octets = this.validStringIP(address);

        for ( int octet : octets ) {
            this.ipAddress = octet + (this.ipAddress << 8);
        }
    }

    public IPv4Address(long address) throws IPAddressException {
        if ( address < 0 || address > maxIP ) { // 0.0.0.0 - 255.255.255.255  // ?
            throw new IPAddressException("Address is too short / too long!"); // ?
        }

        this.ipAddress = address;
    }

    public boolean lessThan(IPv4Address address) {
        return this.ipAddress < address.ipAddress;
    }

    public boolean greaterThan(IPv4Address address) {
        return !this.lessThan(address);
    }

    public boolean equals(IPv4Address address) {
        return this.ipAddress == address.ipAddress;
    }

    public String toString() {
        long ip = this.ipAddress;
        String octets[] = new String[4];

        for ( int i = 3; i >= 0; i-- ) {
            octets[i] = String.valueOf(ip & 255);
            ip >>= 8;
        }

        return String.join(".", octets);
    }

    public long toLong() {
        return this.ipAddress;
    }

    public static void main(String[] args) throws IPAddressException {
        IPv4Address ip = new IPv4Address(4294967295L);
        System.out.println(ip.toString());
        IPv4Address ipp = new IPv4Address("  255.   255      .255.255");
        System.out.println(ipp.toString());
        System.out.println(ipp.toLong());
    }
}
