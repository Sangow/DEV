package Network;

import IPv4Address.IPv4Address;

public class Network {
    private static long mask32 = 4294967295L;

    private int maskLength;
    private long lMask;
    private String sMask;

    private IPv4Address networkAddress;
    private IPv4Address firstNetworkAddress;
    private IPv4Address lastNetworkAddress;
    private IPv4Address broadcastNetworkAddress;

    private String longToStringAddress(long address) {
        String octets[] = new String[4];

        for (int i = 3; i >= 0; i-- ) {
            octets[i] = String.valueOf(address & 255);
            address >>= 8;
        }

        return String.join(".", octets);
    }

    public Network(IPv4Address address, int maskLength) {
        if ( maskLength < 0 || maskLength > 32 ) {
            throw new IllegalArgumentException("Mask is out of range");
        }

        this.maskLength = maskLength;
        this.lMask = mask32 & mask32 << 32 - this.maskLength;
        this.sMask = this.longToStringAddress(this.lMask);
        this.networkAddress = new IPv4Address(address.toLong() & (mask32 << (32 - this.maskLength)));

        if (  this.maskLength == 31 ) {
            this.broadcastNetworkAddress = new IPv4Address(this.networkAddress.toLong() + 1);
            this.firstNetworkAddress = this.lastNetworkAddress = null;
        } else if ( this.maskLength == 32 ) {
            this.broadcastNetworkAddress = null;
            this.firstNetworkAddress = this.lastNetworkAddress = new IPv4Address(this.networkAddress.toLong());
        } else {
            this.broadcastNetworkAddress = new IPv4Address(this.networkAddress.toLong() | ~this.lMask & mask32);
            this.lastNetworkAddress = new IPv4Address(this.broadcastNetworkAddress.toLong() - 1);
            this.firstNetworkAddress = new IPv4Address(this.networkAddress.toLong() + 1);
        }
    }

    public boolean contains(IPv4Address address) {
        return address.greaterThan(this.networkAddress) && address.lessThan(this.broadcastNetworkAddress);
    }

    public IPv4Address getAddress() {
        return this.networkAddress;
    }

    public IPv4Address getBroadcastAddress() {
        return this.broadcastNetworkAddress;
    }

    public IPv4Address getFirstUsableAddress() {
        return this.firstNetworkAddress;
    }

    public IPv4Address getLastUsableAddress() {
        return this.lastNetworkAddress;
    }

    public long getMask() {
        return this.lMask;
    }

    public String getMaskString() {
        return this.sMask;
    }

    public int getMaskLength() {
        return this.maskLength;
    }

    public Network[] getSubnets() {
        if ( this.maskLength > 30 ) {
            return null;
        }

        Network[] subnets = new Network[2];

        subnets[0] = new Network(new IPv4Address(this.networkAddress.toLong()),this.maskLength + 1);
        subnets[1] = new Network(new IPv4Address(subnets[0].broadcastNetworkAddress.toLong() + 1), this.maskLength + 1);

        return subnets;
    }

    public long getTotalHosts() {
        if ( this.maskLength == 31 ) {
            return 0;
        } else if ( this.maskLength == 32 ) {
            return 1;
        } else {
            return this.lastNetworkAddress.toLong() - this.networkAddress.toLong();
        }
    }

    public boolean isPublic() {
        return !new Network(new IPv4Address("10.0.0.0"), 8).contains(this.networkAddress)
                && !new Network(new IPv4Address("172.16.0.0"), 12).contains(this.networkAddress)
                && !new Network(new IPv4Address("192.168.0.0"), 12).contains(this.networkAddress)
                && !new Network(new IPv4Address("127.0.0.0"), 12).contains(this.networkAddress)
                && !this.networkAddress.equals(new IPv4Address("255.255.255.255"));
    }

    @Override
    public String toString() {
        return this.networkAddress.toString() + "/" + this.maskLength;
    }

    public static void main(String[] args) {
        Network net = new Network(new IPv4Address("0.0.0.0"), 0);
//        System.out.println(net.getTotalHosts());
//        net.getFirstUsableAddress().toString();
//        System.out.println(net.getFirstUsableAddress().toString());
//        System.out.println(net.getLastUsableAddress().toString());
//        System.out.println(net.getBroadcastAddress().toString());

        System.out.println(net.getAddress().toLong());
        System.out.println(net.getMask());
//        System.out.println(net.isPublic());
    }
}