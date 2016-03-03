#include "deconstructor.hpp"

using namespace std;


namespace vg {
	Deconstructor::Deconstructor(){

	}

	Deconstructor::Deconstructor(xg::XG x) : my_xg(x){

	}

	Deconstructor::Deconstructor(VG v) : my_vg(v){

	}

	Deconstructor::~Deconstructor(){
	}

	/**
	Use a basic BFS to find nodes on path
	deconstruct(path p){

}
	*/

	/**
	* Another function taken from Brankovic. Takes a potential start and
	* end index for a superbubble.
	* Returns: a SuperBubble struct if one is found. An empty one if
	* no superbubbles are found.
	* Modifies global variables!
	* Should probably have a matching report function which actually returns a bloody superbubble
    * and tosses it in the global namespace.
	*/
	SuperBubble Deconstructor::report_superbubble(int start_ind, int end_ind){
		// This seems iffy, check it.
		if (start_ind == -1 || end_ind == -1 || start_ind >= end_ind){
			candidates.pop_back();
		}
		int s = previous_entrances[end_ind];
		while (ord_D[s] >= ord_D[start_ind]){
            NodeTraversal valid = validate_superbubble(s, end_ind);
            if (s == valid || valid == alternative_entrances[s] || valid = -1){
                break
            }
            alternative_entrance[s] = valid;
            s = valid;
		}
        candidates.pop_back();
        if (valid == s){
        //TODO MAke a superbubble obj and toss it up!
        report(SuperBubble sb);
        //March back from end to s in candidates
        //  if is_exit(candidates.back()){
        //      report_superbubble(candidates[candidates.size() - 2, candidates.back());
        //  }
        //  else{
        //      candidates.pop_back()
        //  }
        }


	}

	/**
	* Implementation of method SuperBubble in Brankovic 2015.
	* Takes a graph (vg), topologically sorts it, and marches
	* backward through the ordered nodes looking for candidates superbubbles.
	* Makes a SuperBubble struct if one is found, and appends it to a vector which
	* is returned. If none are found, the returned vector is empty.
	* Modifies global variables!
	*/
	vector<SuperBubble> Deconstructor::get_all_superbubbles(VG v){
		vector<SuperBubble> ret;
		//deque<NodeTraversal> ord_D;
		v.topological_sort(ord_D);
		NodeTraversal n;
		const int size =  ord_D.size();

		NodeTraversal prev_entr;
		for (int i = ord_D.size(); i >= 0; --i){
			alt_entrances[i] = nullptr;
			previous_entrances[i] = prev_entr;
			if (is_exit(ord_D[i])){
				insert_exit(ord_D[i]);
			}
			if (is_entrance(ord_D[i])){
				insert_entrance(ord_D[i]);
			}
		}

		while(candidates.size() != 0){
			if (is_entrance(candidates.back())){
				candidates.pop_back();
			}
			else{
				report_superbubble(0, candidates.size() - 1);
			}
		}


		return ret;
	}

	/**
	* Take in the indices of potential superbubble entrances/exits
	* and return the index of the actual entrance OR -1 if none found
	* and superbubble isn't so super.
	* Modifies global variables!
	*/
	int Deconstructor::validate_super_bubble(int start, int end){
			NodeTraversal s = ord_D[start];
			NodeTraversal e = ord_D[end];
			NodeTraversal outchild = rangemax(oc, start, end-1);
			NodeTraversal outparent = rangemin(op, start+1, end);
			if (outchild != e){
				return -1;
			}
			if (outparent == start){
				return start;
			}
			else if (is_entrance(outparent)){
				op;
			}
			else{
				return prev_entr[op];
			}
	}

	vector<int64_t> Deconstructor::emit_nodes_on_path_through_superbubble(Path p, vector<SuperBubble> subs){

	}

	vector<int64_t> Deconstructor::emit_nodes_off_path_through_superbubble(SuperBubble sb){

	}

	vector<vcflib::Variant> Deconstructor::sb_to_variants(SuperBubble sb){

	}

	/** Checks whether a vertex V satisifes Lemma 3,
	* that v has one parent vertex.
	*/
	bool Deconstructor::is_exit(NodeTraversal v){
		if (v.backward){
			vector<pair<id_t, bool>>& edges_end = my_vg.edges_end(v.node);
			return edges_end.size() <= 1;
		}
		else{
			vector<pair<id_t, bool>>& edges_start = my_vg.edges_start(v.node);
			return edges_start.size() <= 1;
		}
	}

	bool Deconstructor::is_entrance(NodeTraversal v){
		if (!v.backward){
			vector<pair<id_t, bool>>& edges_end = my_vg.edges_end(v.node);
			return edges_end.size() <= 1;
		}
		else{
			vector<pair<id_t, bool>>& edges_start = my_vg.edges_start(v.node);
			return edges_start.size() <= 1;
		}
	}

	int Deconstructor::rangemin(vector<int> a, int i, int j){

	}

  int Deconstructor::rangemax(vector<int> a, int i, int j){

	}

	void Deconstructor::insert_exit(NodeTraversal n){

	}
	void Deconstructor::insert_entrance( NodeTraversal n){

	}

	NodeTraversal Deconstructor::head(deque<NodeTraversal> cands){

	}

	NodeTraversal Deconstructor::tail(deque<NodeTraversal> cands){

	}

	NodeTraversal Deconstructor::delete_tail(deque<NodeTraversal> cands){

	}
}
