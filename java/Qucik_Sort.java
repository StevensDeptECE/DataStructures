public class Qucik_Sort {
    public static void swap(int[] a, int i, int j){
        int temp = a[j];
        a[j] = a[i];
        a[i] = temp;
    }

    public static void QS(int[] a){
        if (a == null || a.length < 2)
            return;

        Qs_core(a, 0, a.length-1);
    }

    public static void Qs_core(int[] a, int l, int r){
        if (l < r){
            swap(a,r, l + (int)(Math.random() * (r-l+1)));
            int[] p = partition(a, l, r);
            Qs_core(a, l, p[0] -1);
            Qs_core(a, p[1]+1, r);
        }
    }

    public static int[] partition(int[] a, int l, int r){
        int[] bod = { 0, 0};
        int left = l-1;
        int right = r;
        int sign = l;
        while(sign < right) {
            if ( a[r] > a[sign]){
                swap(a, ++left, sign++);
            } else if (a[r] == a[sign]) {
                sign++;
            }else {
                swap(a, --right, sign);
            }
        }
        swap(a, sign, r);
        bod[0] = left + 1;
        bod[1] = right;
        return bod;
    }

    public static void main(String[] args) {
        int[] p = {2,3,1,1,4,4,56,1};
        Qucik_Sort.QS(p);
        for (int i = 0; i < p.length; i++){
            System.out.println(p[i]);
        }
        System.out.println(p[0]+" "+p[1]);
    }
}
