package IPv4Address;

public class IPv4Address {
    private static final long maxIP = 4294967295L;
    private long ipAddress;

    private void setStringIP(String address) throws IPAddressException {
        if ( address == null || address.isEmpty() ) {
            throw new IPAddressException("Address is empty!");
        }

        String[] temp = address.split("\\.");

        if ( temp.length != 4 ) {
            throw new IPAddressException("Incorrect number of octets!");
        }

        int octet;

        for ( String str : temp ) {
            String s = str.trim();

            try {
                octet = Integer.parseInt(s);
            } catch (NumberFormatException nfe) {
                throw new IPAddressException("Invalid data type!");
            }
            if ( octet < 0 || octet > 255 ) {
                throw new IPAddressException("Invalid value in octet!");
            }

            this.ipAddress = octet + (this.ipAddress << 8);
        }
    }

    public IPv4Address(String address) throws IPAddressException {
        this.setStringIP(address);
    }

    public IPv4Address(long address) throws IPAddressException {
        if ( address < 0 || address > maxIP ) { // 0.0.0.0 - 255.255.255.255
            throw new IPAddressException("Address is too short / too long!");
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
        return String.format("%d.%d.%d.%d", (this.ipAddress & 0xFF000000) >> 24,
                                            (this.ipAddress & 0x00FF0000) >> 16,
                                            (this.ipAddress & 0x0000FF00) >> 8,
                                             this.ipAddress & 0x000000FF
                            );
    }

    public long toLong() {
        return this.ipAddress;
    }

    public static void main(String[] args) throws IPAddressException {
        IPv4Address ip = new IPv4Address("255.255.255.255");
        System.out.println(ip);
    }
}
