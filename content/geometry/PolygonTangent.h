/**
 * Author: Ulf Lundstrom
 * Date: 2009-02-26
 * License: CC0
 * Source: My head with inspiration from tinyKACTL
 * Description: Calculates tangents to a polygon from an external point
 * 	dmcp : sgn, getCross : cross
 * Status: Works fine, used a lot
 */

// Calculate [ACW, CW] tangent pair from an external point
    #define CW 		-1
    #define ACW	 	 1
    int direction(Point st, Point ed, Point q)       {return dcmp(getCross(ed - st, q - ed));}
    bool isGood(Point u, Point v, Point Q, int dir)  {return direction(Q, u, v) != -dir;}
    Point better(Point u, Point v, Point Q, int dir) {return direction(Q, u, v) == dir ? u : v;}

    Point tangents(Point* pt, Point Q, int dir, int lo, int hi){
        while(hi - lo > 1){
            int mid = (lo + hi)/2;
            bool pvs = isGood(pt[mid], pt[mid - 1], Q, dir);
            bool nxt = isGood(pt[mid], pt[mid + 1], Q, dir);

            if(pvs && nxt) return pt[mid];
            if(!(pvs || nxt)){
                Point p1 = tangents(pt, Q, dir, mid+1, hi);
                Point p2 = tangents(pt, Q, dir, lo, mid - 1);
                return better(p1, p2, Q, dir);
            }

            if(!pvs){
                if(direction(Q, pt[mid], pt[lo]) == dir)  hi = mid - 1;
                else if(better(pt[lo], pt[hi], Q, dir) == pt[lo]) hi = mid - 1;
                else lo = mid + 1;
            }
            if(!nxt){
                if(direction(Q, pt[mid], pt[lo]) == dir)  lo = mid + 1;
                else if(better(pt[lo], pt[hi], Q, dir) == pt[lo]) hi = mid - 1;
                else lo = mid + 1;
            }
        }

        Point ret = pt[lo];
        for(int i = lo + 1; i <= hi; i++) ret = better(ret, pt[i], Q, dir);
        return ret;
    }

    // [ACW, CW] Tangent
    pair<Point, Point> get_tangents(Point* pt, int n, Point Q){
        Point acw_tan = tangents(pt, Q, ACW, 0, n - 1);
        Point cw_tan = tangents(pt, Q, CW, 0, n - 1);
        return make_pair(acw_tan, cw_tan);
    }
