
$(document).ready(function() {
	$("button").bind( "click" , function(){
		//console.log( $(this).attr("name") );

        $.ajax({
            type: 'POST',
            data: { id_p : $( this ).attr("name") } ,
            beforeSend: function(){ } ,
            success: function( data ){ 
            	console.log( data );
            }
        });
    });

});