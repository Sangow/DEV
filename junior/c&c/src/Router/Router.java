package Router;

import IPv4Address.IPv4Address;
import Network.Network;
import Route.Route;

import java.util.ArrayList;

public class Router {
    private ArrayList<Route> routes;
    private Route defaultRoute;

    public Router(Iterable<Route> routes) { // Should be TreeSet with Comparator(f: address.toLong(), s: metric)
        this.routes = (ArrayList<Route>) routes;

        for ( Route r : this.routes ) {
            if ( r.getNetwork().getAddress().toLong() == 0L && r.getNetwork().getMask() == 0 ) {
                this.defaultRoute = r;
            }
        }

        if ( this.defaultRoute != null ) {
            this.routes.remove( this.defaultRoute );
        }

        for (int i = 0; i < (this.routes.size() - 1); i++) {
            for (int j = 0; j < this.routes.size() - i - 1; j++) {
                if ( this.routes.get(j).getNetwork().getMaskLength() < this.routes.get(j + 1).getNetwork().getMaskLength() ) {
                    Route temp = this.routes.get(j);

                    this.routes.set(j, this.routes.get(j + 1));
                    this.routes.set(j + 1, temp);
                }
            }
        }
    }

    public void addRoute(Route route) {
        if ( this.routes.contains(route) ) {
            return;
        }

        for ( int i = 0; i < this.routes.size(); i++ ) {
            if ( route.getNetwork().getMaskLength() > this.routes.get(i).getNetwork().getMaskLength() ) {
                this.routes.add(i, route);
                return;
            }
        }
        this.routes.add(route);
    }

//    public Route getRouteForAddress(IPv4Address address) {
//        for ( Route r : this.routes ) {
//            if (r.getNetwork().contains(address)) {
//                return r;
//            }
//        }
//        return this.defaultRoute;
//    }

    public Iterable<Route> getRoutes() {
        ArrayList<Route> result = new ArrayList<Route>(this.routes);

        if ( this.defaultRoute != null ) {
            result.add(this.defaultRoute);
        }

        return result;
    }

    public void removeRoute(Route route) {
        this.routes.remove(route);
    }

//    public static void main(String[] args) {
//        List<Route> routes = new ArrayList<Route>() {{
//            add(new Route(new Network(new IPv4Address("0.0.0.0"), 0), new IPv4Address("192.168.0.1"), "en0", 10));
//            add(new Route(new Network(new IPv4Address("192.168.0.0"), 24), null, "en0", 10));
//            add(new Route(new Network(new IPv4Address("10.0.0.0"), 8), new IPv4Address("10.123.0.1"), "en1", 10));
//            add(new Route(new Network(new IPv4Address("10.123.0.0"), 20), null, "en1", 10));
//        }};
//
//        Router router = new Router(routes);
//
//        Route route = router.getRouteForAddress(new IPv4Address("192.168.0.176"));
//        System.out.println(route.getMetric());                  // 10
//        System.out.println(route.getInterfaceName());           // en0
//
//        Network net = route.getNetwork();
//        System.out.println(net.toString());                     // 192.168.0.0/24
//        System.out.println(net.getAddress().toString());        // 192.168.0.0
//
//        route = router.getRouteForAddress(new IPv4Address("10.0.1.1"));
//        System.out.println(route.getMetric());                  // 10
//        System.out.println(route.getInterfaceName());           // en1
//        net = route.getNetwork();
//        System.out.println(net.toString());                     // 10.0.0.0/8
//
//
//        for ( Route r : router.getRoutes() ) {
//            Network n = r.getNetwork();
//            System.out.println(n);
//        }
//    }
}