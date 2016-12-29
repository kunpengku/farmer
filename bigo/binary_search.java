/**
 * Created by fupeng on 2016/12/29.
 */
public class BinarySearch {

    static int  binary_search(int [] tmp, int k){
        int l = 0;
        int r = tmp.length-1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(k < tmp[mid]){
                r = mid-1;
            }else if(k > tmp[mid]){
                l = mid+1;
            }else{
                return mid;
            }
        }
        return -1;
    }

    public static void main(String [] argv){
        System.out.println("123");
        int [] tmp = {1, 25  ,59, 60, 92, 145};

        int ret = binary_search(tmp, 92);
        if(ret < 0) {
            System.out.println("不存在");
        }else{
            System.out.println("存在");
        }
    }
}
