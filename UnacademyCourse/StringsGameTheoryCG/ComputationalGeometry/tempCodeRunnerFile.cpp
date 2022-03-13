// std::vector<Point> minkowski_sum(std::vector<Point> a, std::vector<Point> b) { // input in counter clockwise
//     int n = a.size(), m = b.size();
//     int l = 0;
//     for(int i = 0; i < n; i++) {
//         if(a[i].x < a[l].x || (a[i].x == a[l].x && a[i].y < a[l].y)) {
//             l = i;
//         }
//     }
//     int r = 0;
//     for(int i = 0; i < m; i++) {
//         if(b[i].x < b[r].x || (b[i].x == b[r].x && b[i].y < b[r].y)) {
//             r = i;
//         }
//     }
//     std::vector<Point> result;
//     for(int i = 0; i < n+m; i++) {
//         result.push_back(a[l]+b[r]);
//         if(cross(a[(l+1)%n]-a[l], b[(r+1)%m] - b[r]).z >= 0) {
//             l = (l+1)%n;
//         } else {
//             r = (r+1)%m;
//         }
//     }
//     return result;
// }
