package Network;

import IPv4Address.IPv4Address;
import com.sun.security.jgss.GSSUtil;

public class Network {
    private static long mask32 = 4294967295L;

    private int maskLength;
    private long lMask;
    private String sMask;

    private IPv4Address ipAddress;
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
        this.ipAddress = address;
        this.maskLength = maskLength;
        this.lMask = mask32 & mask32 << 32 - this.maskLength;
        this.sMask = this.longToStringAddress(this.lMask);
        this.networkAddress = new IPv4Address(this.ipAddress.toLong() & (mask32 << (32 - this.maskLength)));
        this.broadcastNetworkAddress = new IPv4Address(this.networkAddress.toLong() | ~this.lMask & mask32);
        this.lastNetworkAddress = new IPv4Address(this.broadcastNetworkAddress.toLong() - 1);
        this.firstNetworkAddress = new IPv4Address(this.networkAddress.toLong() + 1);
    }

    public boolean contains(IPv4Address address) {
        return address.greaterThan(this.networkAddress) && address.lessThan(this.broadcastNetworkAddress);
    }

    public IPv4Address getAddress() {
        return this.ipAddress;
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
        Network[] subnets = new Network[2];

        subnets[0] = new Network(new IPv4Address(this.networkAddress.toLong()),this.maskLength + 1);
        subnets[1] = new Network(new IPv4Address(subnets[0].broadcastNetworkAddress.toLong() + 1), this.maskLength + 1);

        return subnets;
    }

    public long getTotalHosts() {
        return this.lastNetworkAddress.toLong() - this.networkAddress.toLong();
    }

    public boolean isPublic() {
        if ( new Network(new IPv4Address("10.0.0.0"), 8).contains(this.ipAddress)
            || new Network(new IPv4Address("172.16.0.0"), 12).contains(this.ipAddress)
            || new Network(new IPv4Address("192.168.0.0"), 12).contains(this.ipAddress)
            || new Network(new IPv4Address("127.0.0.0"), 12).contains(this.ipAddress)
            || this.ipAddress.equals(new IPv4Address("255.255.255.255"))) {
                return false;
        } else {
            return true;
        }
    }

    @Override
    public String toString() {
        return this.ipAddress.toString() + "/" + this.maskLength;
    }
}
