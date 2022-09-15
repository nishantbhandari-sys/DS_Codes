/*

  Trie (we pronounce "try")   or  "prefix tree"
  is a tree data structure, which is used for retrieval of a key in a dataset of strings. 

Trie node structure:
  Trie is a rooted tree. Its nodes have the following fields:

      Maximum of R links to its children, where each link corresponds to one of R character values from dataset alphabet.
      In this article we assume that R is 26, the number of lowercase latin letters.


      Boolean field which specifies whether the node corresponds to the end of the key, or is just a key prefix. ( here isEnd variable )

For more ref:
    https://leetcode.com/problems/implement-trie-prefix-tree/solution/
  
*/

class Trie {

    class TrieNode{
        private TrieNode[] links;
        
        //  R links to node children
        private final int R = 26;
        
        private boolean isEnd;
        
        TrieNode(){
            links = new TrieNode[ R ];
        }
        
        public void put( char ch, TrieNode node ){
            
            links[ ch -'a' ] = node;
        }
        
        public boolean containsKey( char ch ){
            
            return links[ ch -'a' ] != null;            
        }
        
        public TrieNode get( char ch ){
            
            return links[ ch -'a' ];            
        }
        
        public void setEnd(){
            isEnd = true;
        }        
        public boolean isEnd(){
            return isEnd;
        }
        
    }
    
    TrieNode root;
    
    public Trie() {
        
        root = new TrieNode();
    }
    
    public void insert(String word) {
        
        TrieNode node = root;
        
        for( int i = 0; i < word.length(); i++ ){
            char ch = word.charAt( i );
            
            if( !node.containsKey( ch ) )
                node.put( ch, new TrieNode() );
            
            node = node.get( ch );
        }
        
        node.setEnd();
    }
    
    public boolean search(String word) {
        
        TrieNode node = searchPrefix( word );
        
        return node != null && node.isEnd() ;
    }
    
    public boolean startsWith(String prefix) {
        
        return searchPrefix( prefix ) != null;
    }
    
    public TrieNode searchPrefix(String word) {
        TrieNode node = root;
        
        for( int i = 0; i < word.length(); i++ ){
            char ch = word.charAt( i );
            
            if( !node.containsKey( ch ) )
                return null;
            
            node = node.get( ch );
        }
        
        return node;
    }
    
}
