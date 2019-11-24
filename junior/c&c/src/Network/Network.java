package Network;

import IPv4Address.IPv4Address;
import IPv4Address.IPAddressException;

import java.util.HashSet;

public class Network {
    private static long mask32 = 4294967295L;

    private static HashSet<Network> privateNets;

    private int maskLength;
    private long mask;
    private IPv4Address networkAddress;

    private void validMask(int maskLength) throws IPAddressException {
        if ( maskLength < 0 || maskLength > 32 ) {
            throw new IPAddressException("Mask is out of range");
        }

        this.maskLength = maskLength;
        this.mask = Network.mask32 & Network.mask32 << 32 - this.maskLength;
    }

    private static void initPrivateNets() throws IPAddressException {
        Network.privateNets = new HashSet<Network>(4);

        Network.privateNets.add(new Network(new IPv4Address("10.0.0.0"), 8));
        Network.privateNets.add(new Network(new IPv4Address("172.16.0.0"), 12));
        Network.privateNets.add(new Network(new IPv4Address("192.168.0.0"), 12));
        Network.privateNets.add(new Network(new IPv4Address("127.0.0.0"), 12));
    }

    public Network(IPv4Address address, int maskLength) throws IPAddressException {
        this(address.toLong(), maskLength);
    }

    private Network(long ip, int maskLength) throws IPAddressException {
        this.validMask(maskLength);

        this.networkAddress = new IPv4Address(ip & (Network.mask32 << (32 - this.maskLength)));
    }

    public boolean contains(IPv4Address address) throws IPAddressException {
        return address.greaterThan(this.networkAddress) && address.lessThan(this.getBroadcastAddress());
    }

    public IPv4Address getAddress() {
        return this.networkAddress;
    }

    public IPv4Address getBroadcastAddress() throws IPAddressException {
        if ( this.maskLength == 31 ) {
            return new IPv4Address(this.networkAddress.toLong() + 1L);
        } else if ( this.maskLength == 32 ) {
            return null;
        }
        return new IPv4Address(this.networkAddress.toLong() | ~this.mask & Network.mask32);
    }

    public IPv4Address getFirstUsableAddress() throws IPAddressException {
        if ( this.maskLength == 31 ) {
            return null;
        } else if ( this.maskLength == 32 ) {
            return new IPv4Address(this.networkAddress.toLong());
        }
        return new IPv4Address(this.networkAddress.toLong() + 1L);
    }

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

        subnets[0] = new Network(this.networkAddress.toLong(), this.maskLength + 1);
        subnets[1] = new Network(subnets[0].getBroadcastAddress().toLong() + 1L, this.maskLength + 1);

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

    public boolean isPublic() throws IPAddressException {
        if (Network.privateNets == null) {
            Network.initPrivateNets();
        }

        for ( Network net : Network.privateNets ) {
            if ( net.contains(this.networkAddress) ) {
                return false;
            }
        }
        return true;
    }

    @Override
    public String toString() {
        return this.networkAddress.toString() + "/" + this.maskLength;
    }

    public static void main(String[] args) throws IPAddressException {
        Network net4 = new Network(new IPv4Address("255.255.255.255"), 10);
        Network net3 = new Network(new IPv4Address("255.255.255.255"), 16);
        Network net2 = new Network(new IPv4Address("255.255.255.255"), 20);
        Network net1 = new Network(new IPv4Address("255.255.255.255"), 24);

        System.out.println(net4.getAddress().toLong());
        System.out.println(net3.getAddress().toLong());
        System.out.println(net2.getAddress().toLong());
        System.out.println(net1.getAddress().toLong());
    }
}