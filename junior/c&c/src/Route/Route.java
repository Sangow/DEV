package Route;

import IPv4Address.IPv4Address;
import Network.Network;

public class Route implements Comparable<Route> {
    private int metric;
    private String interfaceName;
    private IPv4Address gateway;
    private Network network;

    public Route(Network network, IPv4Address gateway, String interfaceName, int metric) {
        this.network = network;
        this.gateway = gateway;
        this.interfaceName = interfaceName;
        this.metric = metric;
    }

    public IPv4Address getGateway() {
        return this.gateway;
    }

    public String getInterfaceName() {
        return this.interfaceName;
    }

    public int getMetric() {
        return this.metric;
    }

    public Network getNetwork() {
        return this.network;
    }

    @Override
    public int compareTo(Route route) {
        int result = Long.compare(route.getNetwork().getAddress().toLong(), this.getNetwork().getAddress().toLong());

        if ( result == 0 ) {
            result = Integer.compare(this.getMetric(), route.getMetric());
        }
        return result;
    }

    public String toString() {
        if ( this.gateway == null ) {
            return "net: " + this.network.toString() + ", interface: " + this.interfaceName
                    + ", metric: " + this.metric;
        } else {
            return "net: " + this.network.toString() + ", gateway: " + this.gateway.toString()
                    + ", interface: " + this.interfaceName + ", metric: " + this.metric;
        }
    }
}