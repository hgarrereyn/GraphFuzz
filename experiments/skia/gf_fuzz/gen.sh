

fuzzers=(
    "./FuzzCanvas/api_image_filter"
    "./FuzzCanvas/api_mock_gpu_canvas"
    "./FuzzCanvas/api_null_canvas"
    "./FuzzCanvas/api_raster_n32_canvas"
    "./FuzzCanvas/api_svg_canvas"
    "./FuzzCanvas/image_filter_deserialize"
    "./FuzzDrawFunctions"
    "./FuzzPathMeasure"
    "./FuzzPathOp"
    "./FuzzPolyUtils"
    "./FuzzRegionOp"
    "./FuzzRegionSetPath"
    "./FuzzSkParagraph"
)

for f in ${fuzzers[@]}
do
    (cd $f && gfuzz gen cpp ./schema.yaml . --generate_dry --ignore_keywords SK_WARN_UNUSED_RESULT)
done
