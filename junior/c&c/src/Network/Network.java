package Network;

import IPv4Address.IPv4Address;
import IPv4Address.IPAddressException;

public class Network {
    private static long mask32 = 4294967295L;

    private int maskLength;
    private long mask;

    private IPv4Address networkAddress;
//    private IPv4Address firstNetworkAddress; // ? should be counted when is needed
//    private IPv4Address lastNetworkAddress; // ? should be counted when is needed
//    private IPv4Address broadcastNetworkAddress; // ? should be counted when is needed

    public Network(IPv4Address address, int maskLength) throws IPAddressException { // ?
        if ( maskLength < 0 || maskLength > 32 ) {
            throw new IllegalArgumentException("Mask is out of range");
        }

        this.maskLength = maskLength;
        this.mask = mask32 & mask32 << 32 - this.maskLength;
        this.networkAddress = new IPv4Address(address.toLong() & (mask32 << (32 - this.maskLength)));

//        if (  this.maskLength == 31 ) {
//            this.broadcastNetworkAddress = new IPv4Address(this.networkAddress.toLong() + 1L);
//            this.firstNetworkAddress = this.lastNetworkAddress = null;
//        } else if ( this.maskLength == 32 ) {
//            this.broadcastNetworkAddress = null;
//            this.firstNetworkAddress = this.lastNetworkAddress = new IPv4Address(this.networkAddress.toLong());
//        } else {
//            this.broadcastNetworkAddress = new IPv4Address(this.networkAddress.toLong() | ~this.mask & mask32);
//            this.lastNetworkAddress = new IPv4Address(this.broadcastNetworkAddress.toLong() - 1L);
//            this.firstNetworkAddress = new IPv4Address(this.networkAddress.toLong() + 1L);
//        }
    }

//    private Network(Network net) {
//        this.
//    }

//    public boolean contains(IPv4Address address) {
//        return address.greaterThan(this.networkAddress) && address.lessThan(this.broadcastNetworkAddress);
//    }

    public IPv4Address getAddress() {
        return this.networkAddress;
    }

//    public IPv4Address getBroadcastAddress() {
//        return this.broadcastNetworkAddress;
//    }

    public IPv4Address getBroadcastAddress() throws IPAddressException {
        if ( this.maskLength == 31 ) {
            return new IPv4Address(this.networkAddress.toLong() + 1L);
        } else if ( this.maskLength == 32 ) {
            return null;
        }
        return new IPv4Address(this.networkAddress.toLong() | ~this.mask & mask32);
    }

//    public IPv4Address getFirstUsableAddress() {
//        return this.firstNetworkAddress;
//    }
    public IPv4Address getFirstUsableAddress() throws IPAddressException {
        if ( this.maskLength == 31 ) {
            return null;
        } else if ( this.maskLength == 32 ) {
            return new IPv4Address(this.networkAddress.toLong());
        }
        return new IPv4Address(this.networkAddress.toLong() + 1L);
    }

//    public IPv4Address getLastUsableAddress() {
//        return this.lastNetworkAddress;
//    }

    public IPv4Address getLastUsableAddress() throws IPAddressException {
        if ( this.maskLength == 31 ) {
            return null;
        } else if ( this.maskLength == 32 ) {
            return new IPv4Address(this.networkAddress.toLong());
        }
        return new IPv4Address(this.getBroadcastAddress().toLong() - 1L);
    }

    public long getMask() {
        return this.mask;
    }

    public String getMaskString() {
        return String.valueOf(this.mask);
    }

    public int getMaskLength() {
        return this.maskLength;
    }

    public Network[] getSubnets() throws IPAddressException {
        if ( this.maskLength > 30 ) {
            return null;
        }

        Network[] subnets = new Network[2];

        //subnets[0] = new Network(new IPv4Address(this.networkAddress.toLong()),this.maskLength + 1); // ? Maybe copy this.network with maskLength + 1
        //subnets[1] = new Network(new IPv4Address(subnets[0].broadcastNetworkAddress.toLong() + 1), this.maskLength + 1); // ?
//        subnets[0] = this;
//        subnets[0].

        return subnets;
    }

    public long getTotalHosts() throws IPAddressException {
        if ( this.maskLength == 31 ) {
            return 0;
        } else if ( this.maskLength == 32 ) {
            return 1;
        } else {
            return this.getLastUsableAddress().toLong() - this.networkAddress.toLong();
        }
    }

//    public boolean isPublic() { // ?
//        return !new Network(new IPv4Address("10.0.0.0"), 8).contains(this.networkAddress)
//                && !new Network(new IPv4Address("172.16.0.0"), 12).contains(this.networkAddress)
//                && !new Network(new IPv4Address("192.168.0.0"), 12).contains(this.networkAddress)
//                && !new Network(new IPv4Address("127.0.0.0"), 12).contains(this.networkAddress)
//                && !this.networkAddress.equals(new IPv4Address("255.255.255.255"));
//    }

    @Override
    public String toString() {
        return this.networkAddress.toString() + "/" + this.maskLength;
    }

    public static void main(String[] args) throws IPAddressException {
        Network net = new Network(new IPv4Address("192.168.0.1"), 30);
        System.out.println(net.getTotalHosts());
        System.out.println(net.getFirstUsableAddress().toString());
        System.out.println(net.getLastUsableAddress().toString());
        System.out.println(net.getBroadcastAddress().toString());
//
//        System.out.println(net.getAddress().toLong());
//        System.out.println(net.getMask());
//        System.out.println(net.isPublic());
//        System.out.println(net.contains(new IPv4Address("10.123.14.1")));
    }
}