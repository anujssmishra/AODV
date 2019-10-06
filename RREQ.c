struct RREQ{   
	char source_add[16];
	int broadcast_id;
	int source_seqno;
    char dest_add[16];
	int dest_seqno;
    int hop_count;
}