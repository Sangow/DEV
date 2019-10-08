package Router;

import IPv4Address.IPv4Address;
import Network.Network;
import Route.Route;

import java.util.ArrayList;
import java.util.List;

public class Router {
    public ArrayList<Route> routes;
    private Route defaultRoute;

    public Router(Iterable<Route> routes) {
        this.routes = (ArrayList<Route>)routes;

        for ( Route r : this.routes ) {
            if ( r.getNetwork().getAddress().toLong() == 0L && r.getNetwork().getMask() == 0 ) {
                this.defaultRoute = r;
            }
        }

        if ( this.defaultRoute != null ) {
            this.routes.remove(this.defaultRoute);
        }
    }

    public Route getDefaultRoute() {
        return this.defaultRoute;
    }

    public void addRoute(Route route) {
        if ( this.routes.contains(route) ) {
            return;
        }
        this.routes.add(route);
    }

    public Route getRouteForAddress(IPv4Address address) {
        for ( Route r : this.routes ) {
            if (r.getNetwork().contains(address)) {
                return r;
            }
        }
        return this.defaultRoute;
    }

    public Iterable<Route> getRoutes() {
        ArrayList<Route> result = new ArrayList<Route>();
        result.addAll(this.routes);
        result.add(this.defaultRoute);

        return result;
    }

    public void removeRoute(Route route) {
        this.routes.remove(route);
    }

    public static void main(String[] args) {
        List<Route> routes = new ArrayList<Route>() {{
//            add(new Route(new Network(new IPv4Address("0.0.0.0"), 0), new IPv4Address("192.168.0.1"), "en0", 10));
            add(new Route(new Network(new IPv4Address("192.168.0.0"), 24), null, "en0", 10));
            add(new Route(new Network(new IPv4Address("10.0.0.0"), 8), new IPv4Address("10.123.0.1"), "en1", 10));
            add(new Route(new Network(new IPv4Address("10.123.0.0"), 20), null, "en1", 10));
        }};

        Router router = new Router(routes);

        Route route = router.getRouteForAddress(new IPv4Address("192.168.0.176"));
        System.out.println(route.getMetric());                   // 10
        System.out.println(route.getInterfaceName());           // en0
        Network net = route.getNetwork();
        System.out.println(net.toString());                     // 192.168.0.0/24
        System.out.println(net.getAddress().toString());        // 192.168.0.0

        route = router.getRouteForAddress(new IPv4Address("10.0.1.1"));
        System.out.println(route.getMetric());                  // 10
        System.out.println(route.getInterfaceName());           // en1
        net = route.getNetwork();
        System.out.println(net.toString());                     // 10.0.0.0/8

        System.out.println("---|||---|||---|||---");

        for ( Route rout : router.getRoutes() ) {
            System.out.println(rout);
        }

        System.out.println(routes.size());
    }
}