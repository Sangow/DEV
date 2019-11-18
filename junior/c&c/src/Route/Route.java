package Route;

import IPv4Address.IPv4Address;
import Network.Network;

public class Route {
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