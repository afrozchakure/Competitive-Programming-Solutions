package Medium;

public class CompareVersionNumbers {
        int compareVersion(String version1, String version2) {
            String v1 = "";
            String v2 = "";
            int m = version1.length(), n = version2.length();
            int i = 0, j = 0;

            while(i < m || j < n){
                // processing and filtering : ignoring zeros till next dot(.)
                while(i < m && version1.charAt(i) == '0'){
                    i++;
                }
                while(i < m && version1.charAt(i) != '.'){
                    v1 += version1.charAt(i);
                    i++;
                }

                while(j < n && version2.charAt(j) == '0'){
                    j++;
                }
                while(j < n && version2.charAt(j) != '.'){
                    v2 += version2.charAt(j);
                    j++;
                }

                if(v1.length() < v2.length()){
                    return -1;
                }else if(v2.length() < v1.length()){
                    return 1;
                }

                // compare the integer values for major version
                for(int k = 0; k < v1.length(); k++){
                    if(v1.charAt(k) > v2.charAt(k))
                        return 1;
                    else if (v1.charAt(k) < v2.charAt(k)) {
                        return -1;
                    }
                }

                // reset the subversions
                v1 = "";v2 = "";
                i++;
                j++;

            }
            return 0;
    }

}

