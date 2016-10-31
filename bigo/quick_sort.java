public class quickSort {
    static void swap(int [] src, int i, int j){
        int t = src[i];
        src[i]=src[j];
        src[j]=t;
    }
    static void  quicksort(int [] src, int left, int right){
        int i=left;
        int j=right;

        if(left >= right){
            return;
        }

        int key = src[left];
        while(i!=j){
            while(src[j] >= key && i<j){
                j--;
            }
            while(src[i] <= key && i <j)
                i++;
            if(i<j){
                swap(src,i,j);
            }
        }
        src[left] = src[i];
        src[i]= key;

        quicksort(src,left,i-1);
        quicksort(src,i+1,right);

    }

    public static void main(String[] args) {
        int [] src = {9,8,7,6,5,4,3,3,2,2,1,1,0,-1};
        quicksort(src,0,src.length-1);
        for (int t: src
             ) {
            System.out.println(t);
        }

    }
}
