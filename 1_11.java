// 字符串的集合
// 给定一个字符串的集合,格式如: {aaa bbb ccc}, {bbb ddd}, {eee fff},
// {ggg}, {ddd, hhh}要求将其中交集不为空的集合合并,要求合并完成后的
// 集合之间无交集,例如上例应输出{aaa bbb ccc ddd hhh}, {eee fff}, {ggg}
// 并查集
import java.util.Map;
import java.util.Set;
import java.util.List;
import java.util.HashMap;
import java.util.HashSet;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;

class DisjointSetProblem {
  private final int SIZE= 4;
  private int[] father;
  private static List<Set<String>> resultList = new ArrayList<Set<String>>();

  public static void main(String[] args) {
    String[] str0 = {"aaa", "bbb", "ccc"};
    String[] str1 = {"bbb", "ddd"};
    String[] str2 = {"eee", "fff"};
    String[] str3 = {"ggg"};
    String[][] strs = {str0, str1, str2, str3};

    for (String[] str : strs) {
      Set<String> set = new HashSet<String>();
      set.addAll(Arrays.asList(str));
      resultList.add(set);
    }
    DisjointSetProblem disjointSet = new DisjointSetProblem();
    disjointSet.disjoint(strs);
  }

  /*
   * 获取hashmap的过程
   */
  public void disjoint(String[][] strings) {
    if (strings == null || strings.length < 2) {
      return;
    }
    initial();
    // 获得hashmap: key 为字符串, value 为一个链表
    Map<String, List<Integer>> map = storeInHashMap(strings);
    // 并查集进行合并
    union(map);
  }

  // in the beginning, each elements is in its own "group".
  public void initial() {
    father = new int[SIZE];
    for (int i = 0; i < SIZE; ++i) {
      father[i] = i;
    }
  }

  /*
   * Map<k, v>
   * key: String 
   * value: List<Integer> in which sets the string show up.
   */
  public Map<String, List<Integer>> storeInHashMap(String[][] strings) {
    Map<String, List<Integer>> map = new HashMap<String, List<Integer>>();
    for (int i = 0; i < SIZE; ++i) {
      for (String each : strings[i]) {
        if (!map.containsKey(each)) {
          List<Integer> list = new ArrayList<Integer>();
          list.add(i);
          map.put(each, list);
        } else {
          map.get(each).add(i);
        }
      }
    }
    System.out.println("集合映射所生成的hashmap为: ");
    printMap(map);
    return map;
  }

  private void printMap(Map<String, List<Integer>> map) {
    Iterator<Map.Entry<String, List<Integer>>> iter = 
      map.entrySet().iterator();
    while (iter.hasNext()) {
      Map.Entry<String, List<Integer>> entry = iter.next();
      String key = entry.getKey();
      List<Integer> value = entry.getValue();
      System.out.println(key + " : " + value);
    }
  }

  public  void union(Map<String, List<Integer>> map) {
    Iterator<Map.Entry<String, List<Integer>>> it = 
      map.entrySet().iterator();
    while (it.hasNext()) {
      Map.Entry<String, List<Integer>> entry = it.next();
      List<Integer> value = entry.getValue();
      unionHelp(value);
    }
    // 打印出 father 父节点信息
    System.out.println("hashmap 集合合并之后的父节点信息为: ");
    printFather(father);
    printSetList(resultList);

    for (int i = 0; i < SIZE; ++i) {
      if (i != father[i]) {
        Set<String> dest = resultList.get(father[i]);
        Set<String> source = resultList.get(i);
        dest.addAll(source);
      }
    }
    for (int i = 0; i < SIZE; ++i) {
      if (i != father[i]) {
        resultList.get(i).clear();
      }
    }
    System.out.println("合并后: " + resultList);
  }

  public void unionHelp(List<Integer> list) {
    int minFather = getFather(list.get(0));
    for (int i = 0, size = list.size(); i < size; ++i) {
      unionHelp(list.get(0), list.get(i));
    }
  }

  public int getFather(int x) {
    while (x != father[x]) {
      x = father[x];
    }
    return x;
  }

  private void printFather(int[] fatherNode) {
    for (int node : fatherNode) {
      System.out.println(node + " ");
    }
  }

  private void printSetList(List<Set<String>> list) {
    System.out.println("合并前:");
    for (int i = 0; i < SIZE; ++i) {
      System.out.print(list.get(i) + " ");
    }
    System.out.println();
  }

  public void unionHelp(int x, int y) {
    if (father[x] != father[y]) {
      int fx = getFather(x);
      int fy = getFather(y);
      if (fx < fy) {
        father[y] = fx;
      } else {
        father[x] = fy;
      }
    }
  }
}
