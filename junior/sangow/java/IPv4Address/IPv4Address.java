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

    public static void main(String[] args) {
        IPv4Address ip = new IPv4Address("127.12.45.22");

	ip.toString();  // 127.12.45.22
	ip.toLong();    // 2131504406

	IPv4Address ip2 = new IPv4Address(2131504406);
	System.out.println(ip2.toString());  // 127.12.45.22
	System.out.println(ip2.toLong());    // 2131504406

	System.out.println(ip2.equals(new IPv4Address("127.12.45.22")));        // true
	System.out.println(ip2.equals(new IPv4Address(2131504406L)));           // true
	System.out.println(ip2.equals(new IPv4Address(0xF834AD02L)));           // false
	System.out.println(ip2.equals(new IPv4Address("189.11.23.211")));       // false
	System.out.println(ip2.greaterThan(new IPv4Address("131.16.34.66")));   // false
	System.out.println(ip2.lessThan(new IPv4Address("131.16.34.66"))); 
    }
}
