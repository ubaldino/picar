
var band_take = false;
$(document).ready(function() {
    $("#m_img").hide();
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

    $("button[name='m_push']").bind( "click" , function(){
        if ( band_take ){
            $("#m_img").hide();
            band_take = false;
        }
        else{
            $("#m_img").show();
            band_take = true;
        }
    });

});