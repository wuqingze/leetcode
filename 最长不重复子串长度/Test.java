class Test{
    public static void main(String[] args){
        System.out.println(String.format("select staffId ,staffName,staffNames,staffSurname,staffoffcode from es_staff where staffName like '%%%s%%' order by staffoffcode","hello"));
    }
}